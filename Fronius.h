/* 
 * C Fronius library
 * Copyright (c) 2020 Danielcplusplus and mike-2x.
 * DISCLAIMER: This project is not affiliated with, funded by, or in any way associated with Fronius International GmbH.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
char json[1100];


char * parse(char * source, char * target)
{
	int i=0;
	int x=0;
	int y=0;
	double value_return = 0;
	char * value = malloc(128 * sizeof(char));

	for(i=0;source[i]!=0x00;i++)
	{
		y=1;

		if(source[i]==target[0])
		{
			x=0;
			y=0;

			while(source[i]!='"')
			{
				if(source[i]!=target[x])y++;
				i++;
				x++;
			}
		}

		if(y==0)
		{
			x=0;
			while(source[i]!=':')i++;i++;
			while(source[i]!=',')
			{
				value[x]=source[i];
				x++;
				i++;
			}
		}
		if(y==0)
		{
			source[i+1]=0x00;
		}
	}

	return value;
}

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL)exit(1);
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL)exit(1);

  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

void get_request(char * url, char * dest)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl)
  {
    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);

    sprintf(dest,"%s\n", s.ptr);
    free(s.ptr);

    curl_easy_cleanup(curl);
  }
}

void get_request_without(char * url)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
  }
}

void get_ip_only(char * ip, char * dest)
{
	char url[300] = "";
	strcat(url,"http://");
	strcat(url,ip);
	strcat(url,"/solar_api/v1/GetMeterRealtimeData.cgi?Scope=System&DeviceID=1&DataCollection=CommonInverterData");
	get_request(url,dest);
}

double get_solar_power(char * ip[300])
{
	char search_term[16] = "PowerReal_P_Sum";//Change to what value you want to use

	memset(json, 0, 1100);
	char * powersum;
	double powersum_double;
	get_ip_only(ip, json);
	powersum = parse(json,search_term);
	sscanf(powersum, "%lf", &powersum_double);
	return powersum_double;
}
