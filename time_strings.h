#include<time.h>
#include<ctime.h>

char* time_to_string(time_t time) {
struct tm *tm = localtime(&time);
char time_string[100];
strftime(time_string, 100, "%Y-%M-%d", tm);
return time_string;
}

time_t string_to_time(char* s_time) {
    struct tm date;
    strptime(s_time, "%Y-%M-%d", &date);
    t = mktime(&date);
    return t;
}

int check_if_forbidden(char* time_string,int delay_code) {
//parse string
time_t time_parsed = string_to_time(time_string);

struct tm *local_time = localtime(&time);
time_t time_card_can_be_shown;
switch(delay_code) {
	case 0, ;;
	case 1, ;;
	case 2, ;;
	case 3, ;;
	case 4, ;;

}

}
time_t t = time(NULL);

