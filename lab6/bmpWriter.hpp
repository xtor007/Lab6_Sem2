#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

#pragma pack(push, 1)
typedef struct {
    int8_t id;    
    int8_t id1;               // Завжди дві літери 'B' і 'M'
    int32_t filesize;        //*** Розмір файла в байтах
    int16_t reserved;
    int16_t reserved1;        // 0, 0
    int32_t headersize;      // 54L для 24-бітних зображень
    int32_t infoSize;        // 40L для 24-бітних зображень
    int32_t width;           //*** ширина зображення в пікселях
    int32_t depth;           //*** висота зображення в пікселях
    int16_t biPlanes;        // 1 (для 24-бітних зображень)
    int16_t bits;            // 24 (для 24-бітних зображень)
    int32_t biCompression;   // 0L
    int32_t biSizeImage;     // Можна поставити в 0L для зображень без компрессії (наш варіант)
    int32_t biXPelsPerMeter; // Рекомендована кількість пікселів на метр, можна 0L
    int32_t biYPelsPerMeter; // Те саме, по висоті
    int32_t biClrUsed;       // Для індексованих зображень, можна поставити 0L
    int32_t biClrImportant;  // Те саме
} BMPHEAD;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
     uint8_t redComponent;
     uint8_t greenComponent;
     uint8_t blueComponent;
} PIXELDATA;
#pragma pack(pop)

class bmpWriter {
private:
    BMPHEAD header;
    float*** pixelMap;
    string path, name;
    int height, width;
public:
    bmpWriter(string name, float*** pixelMap, int h, int w);
    void bmpWrite();
};
