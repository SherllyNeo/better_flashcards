#ifndef _LISTH_
#define _LISTH_

#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE 700
#include<time.h>


char* time_to_string_(time_t time) {
	struct tm *tm = localtime(&time);
	static char time_string[100];
	strftime(time_string, 100, "%Y-%m-%d", tm);
	return time_string;
}

time_t string_to_time_(const char* s_time) {
    struct tm date;
    strptime(s_time, "%Y-%m-%d", &date);
    time_t t = mktime(&date);
    return t;
}

 int check_if_forbidden(time_t lastseen,int delay_code) {
 int forbidden = 0;
 int days_to_add = 0;
 //parse string
 struct tm * time_last_seen_tm_p = localtime(&lastseen);
 struct tm time_last_seen_tm = *time_last_seen_tm_p;
 if (delay_code > 4) {
	 days_to_add = 30;
 }
 else if (delay_code > 3) {
	 days_to_add = 14;
 }
 else if (delay_code > 2) {
	 days_to_add = 7;
 }
 else if (delay_code > 1) {
	 days_to_add = 1;
 }
else {
	days_to_add = 0;
}
  time_last_seen_tm.tm_mday += days_to_add;
 time_t date_allowed =  mktime(&time_last_seen_tm);
 time_t date_tday = time(NULL);


 if (date_allowed < date_tday) {
	 forbidden = 1;
 }


 return forbidden;

 }
#endif

