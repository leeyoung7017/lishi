#include "gv.h"

location loc = {0,0,0,0};
db_struct db_loc[64] = {};
QString MotorName[MOTORNUM] = {};
uint8_t flag_continue = 0;
uint8_t flag_reset = 0;
uint8_t flag_stop = 0;
uint8_t flag_run = 0;
uint8_t flag_crc = 0;
uint8_t flag_dialog = 0;

uint8_t flag_scan_slide = 0;
uint8_t flag_scan_tube = 0;
uint8_t flag_scan_tube_enable = 0;
uint8_t flag_scan_slide_enable = 0;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


uint32_t motor_g = 0;
uint32_t step_g = 0;
uint8_t tubes_times = 0;
QMap<QString, int> slides_map;
QMap<QString, tubes_location> tubes_map;

uint32_t step;//坐标
QString loc_str;//发送的坐标所平行轴
ScanCodeGun *scan = new ScanCodeGun();

SerialStruct serialstruct;
SerialStruct scanslidestruct;
SerialStruct scantubestruct;

QThread *sub_slide;
QThread *sub_tube;
QThread *sub_serial;


tubes_location tube_loc[TESTNUM] =
{
    {0,     0 },    {1,     1} ,    {2,     2} ,    {3,     3} ,    {4,     4} ,    {5, 	5} ,    {6,     6} ,    {7,     7} ,
    {8,     8 },    {9,     9} ,    {10,	10},    {11,	11},    {12,	12},    {13,	13},    {14,	14},    {15,	15},
    {16,	16},    {17,	17},    {18,	18},    {19,	19},    {20,	20},    {21,	21},    {22,	22},    {23,	23},
    {24,	24},    {25,	25},    {26,	26},    {27,	27},    {28,	28},    {29,	29},    {30,	30},    {31,	31},
    {32,	32},    {33,	33},    {34,	34},    {35,	35},    {36,	36},    {37,	37},    {38,	38},    {39,	39},
    {40,	40},    {41,	41},    {42,	42},    {43,	43},    {44,	44},    {45,	45},    {46,	46},    {47,	47},
    {48,	48},    {49,	49},    {50,	50},    {51,	51},    {52,	52},    {53,	53},    {54,	54},    {55,	55},
    {56,	56},    {57,	57},    {58,	58},    {59,	59},    {60,	60},    {61,	61},    {62,	62},    {63,	63}
};



//file *csv;
//sqlite *sql;
