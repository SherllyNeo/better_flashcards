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

// int check_if_forbidden(char* time_string,int delay_code) {
// //parse string
// time_t time_parsed = string_to_time(time_string);
//
// struct tm *local_time = localtime(&time);
// time_t time_card_can_be_shown;
// switch(delay_code) {
// 	case 0, ;;
// 	case 1, ;;
// 	case 2, ;;
// 	case 3, ;;
// 	case 4, ;;
//
// }
//
// }
// time_t t = time(NULL);
#endif

