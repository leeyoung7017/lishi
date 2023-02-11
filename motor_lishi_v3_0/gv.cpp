#include "gv.h"

location loc = {0,0,0};
db_struct db_loc[64] = {};
uint8_t flag_continue = 0;
uint8_t flag_reset = 0;
uint8_t flag_stop = 0;
uint8_t flag_run = 0;

uint8_t flag_scan_slide = 0;
uint8_t flag_scan_tube = 0;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
