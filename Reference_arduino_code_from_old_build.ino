// Required Libraries
#include <WiFi.h>
#include "time.h"

// Board I/O
#define r1 14
#define r2 15

// Variable Setup
int start_minute;
int next_trigger;

// Network Credentials
const char* ssid       = "";
const char* password   = "";

// Server and Time Setup
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -5 * 3600;
const int   daylightOffset_sec = 3600;

// Fogger and Light Data
bool flag_fogger = 0;
int fogger_timeOn = 30; //seconds
int fogger_timeOff = 30; //minutes
bool flag_light = 0;
int light_start = 8; //hour
int light_end = 22; //hour

// Date and Time Info
int second;
int minute;
int hour;
int day;
int month;
int year;
int weekday;
long current;
struct tm timeinfo;
/*
  struct tm
  {
  int    tm_sec;   //   Seconds [0,60].
  int    tm_min;   //   Minutes [0,59].
  int    tm_hour;  //   Hour [0,23].
  int    tm_mday;  //   Day of month [1,31].
  int    tm_mon;   //   Month of year [0,11].
  int    tm_year;  //   Years since 1900.
  int    tm_wday;  //   Day of week [0,6] (Sunday =0).
  int    tm_yday;  //   Day of year [0,365].
  int    tm_isdst; //   Daylight Savings flag.
  }
*/

void setup()
{
  Serial.begin(115200);

  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  // Start Time and Set Next Trigger Time
  start_minute = timeinfo.tm_min;
  next_trigger = start_minute + fogger_timeOff;
  if (next_trigger >= 60) {
    next_trigger = next_trigger - 60;
  }

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  // Set Output Pins
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);

  // Ensure Electronics Default Off
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
}

void loop()
{
  delay(1000);
  printLocalTime();
  time_components();
  fogger();
  light();
}

void printLocalTime()
{
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void time_components()
{
  second = timeinfo.tm_sec;
  minute = timeinfo.tm_min;
  hour = timeinfo.tm_hour;
  day = timeinfo.tm_mday;
  month = timeinfo.tm_mon + 1;
  year = timeinfo.tm_year + 1900;
  weekday = timeinfo.tm_wday + 1;
}

void fogger() {
  if (minute == next_trigger) {
    if (second >= 0 && second <= fogger_timeOn) {
      digitalWrite(r1, HIGH);
      Serial.println("Fogger: ON");
    }
    else {
      digitalWrite(r1, LOW);
      next_trigger = next_trigger + fogger_timeOff;
      if (next_trigger >= 60) {
        next_trigger = next_trigger - 60;
      }
      Serial.println("Fogger: OFF");
    }
  }
  else {
    digitalWrite(r1, LOW);
    Serial.println("Fogger: OFF");
  }
  Serial.print("Next Trigger: ");
  Serial.println(next_trigger);
}

void light()
{
//  if (hour >= light_start && hour < light_end) {
//    if (flag_light == 0) {
//      flag_light = 1;
//    }
//  }
//  if (flag_light == 1) {
//    digitalWrite(r2, HIGH);
//    Serial.println("Light: ON");
//  }
//  if (flag_light == 0) {
//    digitalWrite(r2, LOW);
//    Serial.println("Light: OFF");
//  }

  if (hour >= light_start && hour < light_end) {
    digitalWrite(r2, HIGH);
    Serial.println("Light: ON");
  }
  else {
    digitalWrite(r2, LOW);
    Serial.println("Light: OFF");      
  }
}
