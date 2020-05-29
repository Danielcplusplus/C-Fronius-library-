//This file was created by Danielcpluplus and mike-2x
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
char json[1100];


double parse(char * source, char * target)
{
	int i=0;
	int x=0;
	int y=0;
	double value_return = 0;
	char value[32];

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
			printf("\nValue: %s\n\n",value);
			source[i+1]=0x00;
		}
	}

	sscanf(value, "%lf", &value_return);

	return value_return;
}





struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "Memory error 1\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "Memory error 2\n");
    exit(EXIT_FAILURE);
  }
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
  if(curl) {
    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);

    sprintf(dest,"%s\n", s.ptr);
    free(s.ptr);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
}

  void get_request_without(char * url)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    struct string s;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

  }
}//version with request to plug13

double get_solar_power(char * ip[300]){
	char search_term[16] = "PowerReal_P_Sum";//Change to what Value You want to Use

	memset(json, 0, 1100);
	double powersum;
	char url[300] = "";
	strcat(url,"http://");
	strcat(url,ip);
	strcat(url,"/solar_api/v1/GetMeterRealtimeData.cgi?Scope=System&DeviceID=1&DataCollection=CommonInverterData");
	//printf("%s",url);
	get_request(url,json);//Change Ip Adress to your IP
	powersum = parse(json,search_term);
	return powersum;
}

