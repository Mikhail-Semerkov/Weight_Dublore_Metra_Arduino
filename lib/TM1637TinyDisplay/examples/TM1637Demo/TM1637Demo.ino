//  TM1637TinyDisplay DEMO Sketch
//  This is a demo sketch for the Arduino TM1637TinyDisplay LED Display library
//
//  Author: Jason A. Cox - @jasonacox
//  Date: 2 July 2020
//

// Includes
#include <Arduino.h>
#include <TM1637TinyDisplay.h>

// Define Digital Pins
#define CLK 4
#define DIO 5

// Initialize TM1637TinyDisplay - 4 Digit Display
TM1637TinyDisplay display(CLK, DIO);
// Initialize TM1637TinyDisplay - 6 Digit Display
// TM1637TinyDisplay6 display(CLK, DIO);

// Animations created with Tool https://jasonacox.github.io/TM1637TinyDisplay/examples/7-segment-animator.html

const uint8_t ANIMATION1[40][4] PROGMEM = {
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 0
  { 0x01, 0x00, 0x00, 0x00 },  // Frame 1
  { 0x40, 0x01, 0x00, 0x00 },  // Frame 2
  { 0x08, 0x40, 0x00, 0x01 },  // Frame 3
  { 0x00, 0x08, 0x01, 0x40 },  // Frame 4
  { 0x01, 0x00, 0x40, 0x08 },  // Frame 5
  { 0x40, 0x01, 0x08, 0x00 },  // Frame 6
  { 0x08, 0x40, 0x00, 0x01 },  // Frame 7
  { 0x00, 0x08, 0x01, 0x40 },  // Frame 8
  { 0x01, 0x01, 0x40, 0x08 },  // Frame 9
  { 0x40, 0x40, 0x09, 0x00 },  // Frame 10
  { 0x08, 0x08, 0x40, 0x01 },  // Frame 11
  { 0x01, 0x00, 0x08, 0x40 },  // Frame 12
  { 0x40, 0x01, 0x00, 0x08 },  // Frame 13
  { 0x08, 0x40, 0x01, 0x00 },  // Frame 14
  { 0x01, 0x09, 0x41, 0x01 },  // Frame 15
  { 0x40, 0x40, 0x48, 0x40 },  // Frame 16
  { 0x08, 0x08, 0x08, 0x08 },  // Frame 17
  { 0x1c, 0x1c, 0x1c, 0x1c },  // Frame 18
  { 0x3e, 0x3e, 0x3e, 0x3e },  // Frame 19
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 20
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 21
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 22
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 23
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 24
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 25
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 26
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 27
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 28
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 29
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 30
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 31
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 32
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 33
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 34
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 35
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 36
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 37
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 38
  { 0x3f, 0x3f, 0x3f, 0x3f }   // Frame 39
};

const uint8_t ANIMATION2[33][4] PROGMEM = {
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 0
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 1
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 2
  { 0x00, 0x00, 0x00, 0x08 },  // Frame 3
  { 0x00, 0x00, 0x00, 0x04 },  // Frame 4
  { 0x00, 0x00, 0x00, 0x02 },  // Frame 5
  { 0x00, 0x00, 0x00, 0x01 },  // Frame 6
  { 0x00, 0x00, 0x01, 0x00 },  // Frame 7
  { 0x00, 0x01, 0x00, 0x00 },  // Frame 8
  { 0x01, 0x00, 0x00, 0x00 },  // Frame 9
  { 0x20, 0x00, 0x00, 0x00 },  // Frame 10
  { 0x10, 0x00, 0x00, 0x00 },  // Frame 11
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 12
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 13
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 14
  { 0x00, 0x00, 0x04, 0x00 },  // Frame 15
  { 0x00, 0x00, 0x02, 0x00 },  // Frame 16
  { 0x00, 0x00, 0x01, 0x00 },  // Frame 17
  { 0x00, 0x01, 0x00, 0x00 },  // Frame 18
  { 0x00, 0x20, 0x00, 0x00 },  // Frame 19
  { 0x00, 0x10, 0x00, 0x00 },  // Frame 20
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 21
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 22
  { 0x00, 0x00, 0x00, 0x08 },  // Frame 23
  { 0x00, 0x00, 0x00, 0x04 },  // Frame 24
  { 0x00, 0x00, 0x00, 0x02 },  // Frame 25
  { 0x00, 0x00, 0x00, 0x01 },  // Frame 26
  { 0x00, 0x00, 0x01, 0x00 },  // Frame 27
  { 0x00, 0x01, 0x00, 0x00 },  // Frame 28
  { 0x01, 0x00, 0x00, 0x00 },  // Frame 29
  { 0x20, 0x00, 0x00, 0x00 },  // Frame 30
  { 0x10, 0x00, 0x00, 0x00 },  // Frame 31
  { 0x00, 0x00, 0x00, 0x00 }   // Frame 32
};

const uint8_t ANIMATION3[218][4] PROGMEM = {
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 0
  { 0x40, 0x08, 0x00, 0x00 },  // Frame 1
  { 0x01, 0x40, 0x08, 0x00 },  // Frame 2
  { 0x00, 0x01, 0x40, 0x08 },  // Frame 3
  { 0x00, 0x00, 0x01, 0x40 },  // Frame 4
  { 0x00, 0x00, 0x00, 0x01 },  // Frame 5
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 6
  { 0x63, 0x00, 0x00, 0x00 },  // Frame 7
  { 0x00, 0x5c, 0x00, 0x00 },  // Frame 8
  { 0x00, 0x00, 0x63, 0x00 },  // Frame 9
  { 0x00, 0x00, 0x00, 0x5c },  // Frame 10
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 11
  { 0x01, 0x01, 0x01, 0x01 },  // Frame 12
  { 0x41, 0x41, 0x41, 0x41 },  // Frame 13
  { 0x49, 0x49, 0x49, 0x49 },  // Frame 14
  { 0x79, 0x49, 0x49, 0x49 },  // Frame 15
  { 0x7f, 0x49, 0x49, 0x49 },  // Frame 16
  { 0x7f, 0x79, 0x49, 0x49 },  // Frame 17
  { 0x7f, 0x7f, 0x49, 0x49 },  // Frame 18
  { 0x7f, 0x7f, 0x79, 0x49 },  // Frame 19
  { 0x7f, 0x7f, 0x7f, 0x49 },  // Frame 20
  { 0x7f, 0x7f, 0x7f, 0x79 },  // Frame 21
  { 0x7f, 0x7f, 0x7f, 0x7f },  // Frame 22
  { 0x3f, 0x7f, 0x7f, 0x7f },  // Frame 23
  { 0x3f, 0x3f, 0x7f, 0x7f },  // Frame 24
  { 0x3f, 0x3f, 0x3f, 0x7f },  // Frame 25
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 26
  { 0x1e, 0x3f, 0x3f, 0x3f },  // Frame 27
  { 0x0c, 0x3f, 0x3f, 0x3f },  // Frame 28
  { 0x00, 0x1e, 0x3f, 0x3f },  // Frame 29
  { 0x00, 0x0c, 0x3f, 0x3f },  // Frame 30
  { 0x00, 0x00, 0x1e, 0x3f },  // Frame 31
  { 0x00, 0x00, 0x0c, 0x3f },  // Frame 32
  { 0x00, 0x00, 0x00, 0x1e },  // Frame 33
  { 0x00, 0x00, 0x00, 0x0c },  // Frame 34
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 35
  { 0x00, 0x00, 0x00, 0x08 },  // Frame 36
  { 0x00, 0x00, 0x00, 0x10 },  // Frame 37
  { 0x00, 0x00, 0x00, 0x20 },  // Frame 38
  { 0x00, 0x00, 0x00, 0x01 },  // Frame 39
  { 0x00, 0x00, 0x00, 0x02 },  // Frame 40
  { 0x00, 0x00, 0x00, 0x04 },  // Frame 41
  { 0x00, 0x00, 0x00, 0x08 },  // Frame 42
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 43
  { 0x00, 0x00, 0x10, 0x00 },  // Frame 44
  { 0x00, 0x00, 0x20, 0x00 },  // Frame 45
  { 0x00, 0x00, 0x01, 0x00 },  // Frame 46
  { 0x00, 0x00, 0x02, 0x00 },  // Frame 47
  { 0x00, 0x00, 0x04, 0x00 },  // Frame 48
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 49
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 50
  { 0x00, 0x10, 0x00, 0x00 },  // Frame 51
  { 0x00, 0x20, 0x00, 0x00 },  // Frame 52
  { 0x00, 0x01, 0x00, 0x00 },  // Frame 53
  { 0x00, 0x02, 0x00, 0x00 },  // Frame 54
  { 0x00, 0x04, 0x00, 0x00 },  // Frame 55
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 56
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 57
  { 0x10, 0x00, 0x00, 0x00 },  // Frame 58
  { 0x20, 0x00, 0x00, 0x00 },  // Frame 59
  { 0x01, 0x00, 0x00, 0x00 },  // Frame 60
  { 0x02, 0x00, 0x00, 0x00 },  // Frame 61
  { 0x04, 0x00, 0x00, 0x00 },  // Frame 62
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 63
  { 0x18, 0x00, 0x00, 0x00 },  // Frame 64
  { 0x38, 0x00, 0x00, 0x00 },  // Frame 65
  { 0x39, 0x00, 0x00, 0x00 },  // Frame 66
  { 0x39, 0x01, 0x00, 0x00 },  // Frame 67
  { 0x39, 0x01, 0x01, 0x00 },  // Frame 68
  { 0x39, 0x01, 0x01, 0x01 },  // Frame 69
  { 0x39, 0x01, 0x01, 0x03 },  // Frame 70
  { 0x39, 0x01, 0x01, 0x07 },  // Frame 71
  { 0x39, 0x01, 0x01, 0x0f },  // Frame 72
  { 0x39, 0x01, 0x09, 0x0f },  // Frame 73
  { 0x39, 0x09, 0x09, 0x0f },  // Frame 74
  { 0x06, 0x09, 0x09, 0x30 },  // Frame 75
  { 0x00, 0x39, 0x0f, 0x00 },  // Frame 76
  { 0x00, 0x06, 0x30, 0x00 },  // Frame 77
  { 0x00, 0x46, 0x70, 0x00 },  // Frame 78
  { 0x40, 0x06, 0x30, 0x40 },  // Frame 79
  { 0x30, 0x06, 0x30, 0x06 },  // Frame 80
  { 0x30, 0x30, 0x06, 0x06 },  // Frame 81
  { 0x36, 0x00, 0x00, 0x36 },  // Frame 82
  { 0x30, 0x00, 0x00, 0x06 },  // Frame 83
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 84
  { 0x4c, 0x00, 0x00, 0x00 },  // Frame 85
  { 0x00, 0x4c, 0x00, 0x00 },  // Frame 86
  { 0x00, 0x00, 0x4c, 0x00 },  // Frame 87
  { 0x00, 0x00, 0x00, 0x4c },  // Frame 88
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 89
  { 0x00, 0x00, 0x00, 0x61 },  // Frame 90
  { 0x00, 0x00, 0x61, 0x00 },  // Frame 91
  { 0x00, 0x61, 0x00, 0x00 },  // Frame 92
  { 0x61, 0x00, 0x00, 0x00 },  // Frame 93
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 94
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 95
  { 0x00, 0x00, 0x5c, 0x00 },  // Frame 96
  { 0x00, 0x08, 0x7f, 0x08 },  // Frame 97
  { 0x00, 0x0c, 0x7f, 0x18 },  // Frame 98
  { 0x00, 0x5e, 0x7f, 0x7c },  // Frame 99
  { 0x08, 0x7f, 0x7f, 0x7f },  // Frame 100
  { 0x0c, 0x7f, 0x7f, 0x7f },  // Frame 101
  { 0x5e, 0x7f, 0x7f, 0x7f },  // Frame 102
  { 0x7f, 0x7f, 0x7f, 0x7f },  // Frame 103
  { 0x7e, 0x7e, 0x7e, 0x7e },  // Frame 104
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 105
  { 0x77, 0x77, 0x77, 0x77 },  // Frame 106
  { 0x7f, 0x7f, 0x7f, 0x7f },  // Frame 107
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 108
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 109
  { 0x7f, 0x7f, 0x7f, 0x7f },  // Frame 110
  { 0x7f, 0x7f, 0x7f, 0x7f },  // Frame 111
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 112
  { 0x3f, 0x3f, 0x3f, 0x3f },  // Frame 113
  { 0x3f, 0x3f, 0x3f, 0x39 },  // Frame 114
  { 0x3f, 0x3f, 0x3f, 0x30 },  // Frame 115
  { 0x3f, 0x3f, 0x3f, 0x00 },  // Frame 116
  { 0x3f, 0x3f, 0x39, 0x00 },  // Frame 117
  { 0x3f, 0x3f, 0x30, 0x00 },  // Frame 118
  { 0x3f, 0x3f, 0x00, 0x00 },  // Frame 119
  { 0x3f, 0x39, 0x00, 0x00 },  // Frame 120
  { 0x3f, 0x30, 0x00, 0x00 },  // Frame 121
  { 0x3f, 0x00, 0x00, 0x00 },  // Frame 122
  { 0x39, 0x00, 0x00, 0x00 },  // Frame 123
  { 0x30, 0x00, 0x00, 0x00 },  // Frame 124
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 125
  { 0x38, 0x00, 0x00, 0x00 },  // Frame 126
  { 0x3f, 0x38, 0x00, 0x00 },  // Frame 127
  { 0x38, 0x3f, 0x38, 0x00 },  // Frame 128
  { 0x00, 0x38, 0x3f, 0x38 },  // Frame 129
  { 0x00, 0x00, 0x38, 0x3f },  // Frame 130
  { 0x00, 0x00, 0x00, 0x38 },  // Frame 131
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 132
  { 0x40, 0x00, 0x00, 0x00 },  // Frame 133
  { 0x00, 0x40, 0x00, 0x00 },  // Frame 134
  { 0x00, 0x00, 0x40, 0x00 },  // Frame 135
  { 0x00, 0x00, 0x00, 0x46 },  // Frame 136
  { 0x00, 0x00, 0x00, 0x39 },  // Frame 137
  { 0x40, 0x00, 0x06, 0x09 },  // Frame 138
  { 0x00, 0x40, 0x39, 0x09 },  // Frame 139
  { 0x40, 0x06, 0x09, 0x09 },  // Frame 140
  { 0x00, 0x39, 0x09, 0x09 },  // Frame 141
  { 0x46, 0x09, 0x09, 0x09 },  // Frame 142
  { 0x39, 0x09, 0x09, 0x09 },  // Frame 143
  { 0x09, 0x09, 0x09, 0x0f },  // Frame 144
  { 0x09, 0x09, 0x09, 0x79 },  // Frame 145
  { 0x09, 0x09, 0x0f, 0x00 },  // Frame 146
  { 0x09, 0x09, 0x79, 0x00 },  // Frame 147
  { 0x09, 0x0f, 0x09, 0x00 },  // Frame 148
  { 0x09, 0x79, 0x00, 0x00 },  // Frame 149
  { 0x0f, 0x09, 0x00, 0x00 },  // Frame 150
  { 0x79, 0x00, 0x00, 0x00 },  // Frame 151
  { 0x30, 0x00, 0x00, 0x00 },  // Frame 152
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 153
  { 0x01, 0x00, 0x00, 0x00 },  // Frame 154
  { 0x08, 0x00, 0x00, 0x00 },  // Frame 155
  { 0x00, 0x01, 0x00, 0x00 },  // Frame 156
  { 0x00, 0x08, 0x00, 0x00 },  // Frame 157
  { 0x00, 0x00, 0x01, 0x00 },  // Frame 158
  { 0x00, 0x00, 0x08, 0x00 },  // Frame 159
  { 0x00, 0x00, 0x00, 0x01 },  // Frame 160
  { 0x00, 0x00, 0x00, 0x08 },  // Frame 161
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 162
  { 0x00, 0x00, 0x00, 0x6d },  // Frame 163
  { 0x00, 0x00, 0x6d, 0x73 },  // Frame 164
  { 0x00, 0x6d, 0x73, 0x77 },  // Frame 165
  { 0x6d, 0x73, 0x77, 0x39 },  // Frame 166
  { 0x73, 0x77, 0x39, 0x79 },  // Frame 167
  { 0x77, 0x39, 0x79, 0x00 },  // Frame 168
  { 0x39, 0x79, 0x00, 0x00 },  // Frame 169
  { 0x79, 0x00, 0x00, 0x00 },  // Frame 170
  { 0x00, 0x00, 0x00, 0x00 },  // Frame 171
  { 0x79, 0x00, 0x00, 0x00 },  // Frame 172
  { 0x00, 0x79, 0x00, 0x00 },  // Frame 173
  { 0x00, 0x00, 0x79, 0x00 },  // Frame 174
  { 0x00, 0x00, 0x00, 0x79 },  // Frame 175
  { 0x10, 0x00, 0x00, 0x79 },  // Frame 176
  { 0x74, 0x00, 0x00, 0x79 },  // Frame 177
  { 0x00, 0x74, 0x00, 0x79 },  // Frame 178
  { 0x00, 0x00, 0x74, 0x79 },  // Frame 179
  { 0x78, 0x00, 0x74, 0x79 },  // Frame 180
  { 0x00, 0x78, 0x74, 0x79 },  // Frame 181
  { 0x00, 0x78, 0x74, 0x79 },  // Frame 182
  { 0x00, 0x78, 0x74, 0x79 },  // Frame 183
  { 0x78, 0x74, 0x79, 0x00 },  // Frame 184
  { 0x74, 0x79, 0x00, 0x00 },  // Frame 185
  { 0x79, 0x00, 0x00, 0x00 },  // Frame 186
  { 0x79, 0x00, 0x00, 0x00 },  // Frame 187
  { 0x79, 0x00, 0x00, 0x04 },  // Frame 188
  { 0x79, 0x00, 0x00, 0x54 },  // Frame 189
  { 0x79, 0x00, 0x54, 0x00 },  // Frame 190
  { 0x79, 0x54, 0x00, 0x00 },  // Frame 191
  { 0x79, 0x54, 0x00, 0x04 },  // Frame 192
  { 0x79, 0x54, 0x00, 0x5e },  // Frame 193
  { 0x79, 0x54, 0x04, 0x30 },  // Frame 194
  { 0x79, 0x54, 0x5e, 0x00 },  // Frame 195
  { 0x79, 0x54, 0x5e, 0x00 },  // Frame 196
  { 0x79, 0x55, 0x5e, 0x02 },  // Frame 197
  { 0x79, 0x54, 0x5e, 0x10 },  // Frame 198
  { 0xf9, 0x54, 0x5e, 0x20 },  // Frame 199
  { 0x79, 0xd4, 0x5e, 0x08 },  // Frame 200
  { 0x79, 0x54, 0x5e, 0x00 },  // Frame 201
  { 0x69, 0x54, 0x5e, 0x00 },  // Frame 202
  { 0x79, 0x54, 0x5e, 0x00 },  // Frame 203
  { 0x79, 0x54, 0x1e, 0x00 },  // Frame 204
  { 0x79, 0x54, 0x5e, 0x00 },  // Frame 205
  { 0x79, 0x14, 0x5e, 0x00 },  // Frame 206
  { 0x68, 0x14, 0x5e, 0x00 },  // Frame 207
  { 0x68, 0x14, 0x1e, 0x00 },  // Frame 208
  { 0x68, 0x14, 0x16, 0x00 },  // Frame 209
  { 0x68, 0x04, 0x16, 0x00 },  // Frame 210
  { 0x28, 0x04, 0x16, 0x00 },  // Frame 211
  { 0x28, 0x04, 0x14, 0x00 },  // Frame 212
  { 0x08, 0x04, 0x14, 0x00 },  // Frame 213
  { 0x08, 0x04, 0x04, 0x00 },  // Frame 214
  { 0x00, 0x04, 0x04, 0x00 },  // Frame 215
  { 0x00, 0x00, 0x04, 0x00 },  // Frame 216
  { 0x00, 0x00, 0x00, 0x00 }   // Frame 217
};

void setup() {
  display.setBrightness(BRIGHT_7);
  display.showNumber(1234);
  delay(1000);

}
void loop() {

  // Say Hello
  display.showString("HELLO");
  delay(500);

  // Clear Screen
  display.clear();

  // We can count!
  for (int x = -110; x <= 100; x++) {
    display.showNumber(x);
    yield(); // Keep watchdog timer happy
  }
  delay(500);

  for (int x = -100; x < 100; x = x + 1) {
    display.showNumber((float)x / 10.0);
    yield(); // Keep watchdog timer happy
  }
  delay(500);

  // Demo Brightness Levels
  char string[10];
  for (int x = 0; x < 8; x++) {
    display.setBrightness(x);
    sprintf(string, "On %d", x);
    display.showString(string);
    delay(1000);
  }

  // Demo Horizontal Level Meter
  for (int count = 0; count < 3; count++) {
    for (int x = 0; x <= 100; x = x + 10) {
      display.showLevel(x, true);
      delay(20);
    }
    for (int x = 100; x >= 0; x = x - 10) {
      display.showLevel(x, true);
      delay(20);
    }
  }
  // Demo Vertical Level Meter
  for (int count = 0; count < 3; count++) {
    for (int x = 0; x <= 100; x = x + 10) {
      display.showLevel(x, false);
      delay(20);
    }
    for (int x = 100; x >= 0; x = x - 10) {
      display.showLevel(x, false);
      delay(20);
    }
  }
  delay(1000);

  // Demo split screen for temperature
  display.showString("\xB0", 1, 3);        // Degree Mark, length=1, position=3 (right)
  for (int x = -90; x < 200; x++) {
    display.showNumber(x, false, 3, 0);    // Number, length=3, position=0 (left)
    delay(10);
  }
  delay(1000);

  // Animation sequences - All in PROGMEM flash memory
  display.clear();
  display.showString("For Fun");
  delay(1000);
  display.showAnimation_P(ANIMATION1, FRAMES(ANIMATION1), TIME_MS(50));
  display.showAnimation_P(ANIMATION2, FRAMES(ANIMATION2), TIME_MS(50));
  display.showAnimation_P(ANIMATION3, FRAMES(ANIMATION3), TIME_MS(50));

  delay(5000);

}
