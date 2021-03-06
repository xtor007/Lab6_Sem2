#include "bmpWriter.hpp"

bmpWriter::bmpWriter(string name, float*** pixelMap, int h, int w): path(std::__fs::filesystem::current_path().string()), name(name), pixelMap(pixelMap), height(h), width(w) {
    int nullBites = 4 - ((w * 3) % 4);
    int fileSize = h * (w * 3 + nullBites);
    header = {'B', 'M', fileSize , 0, 0, 54, 40, w, h, 1, 24, 0, fileSize - 54, 2834, 2834, 0, 0};
}

void bmpWriter::bmpWrite() {
    ofstream out(path + "\\" + name, ios::binary);
    out.write((char*)&header, sizeof(BMPHEAD));
//    int nullBites = 4 - ((width * 3) % 4);
//    uint8_t nullValue = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            PIXELDATA pixel = {static_cast<uint8_t>(abs(pixelMap[i][j][0]) * 255), static_cast<uint8_t>(abs(pixelMap[i][j][1]) * 255), static_cast<uint8_t>(abs(pixelMap[i][j][2])* 255)};
            out.write((char*)&pixel, sizeof(PIXELDATA));
        } 
    }

    out.close();
}
