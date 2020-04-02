#include <iostream>
#include "UTPod.h"
#include "Song.h"

int main() {
    UtPod pod;
    Song newSong("In Your Arms", "Illenium", 4);
    pod.addSong(newSong);
    return 0;
}
