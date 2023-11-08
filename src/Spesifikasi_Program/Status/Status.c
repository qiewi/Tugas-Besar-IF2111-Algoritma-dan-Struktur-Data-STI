#include "../Play/Play.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../Queue/Queue.h"
#include "Status.h"

void Status(CurrentSong * CS, QueueLagu  * QL)
{
    if ((*CS).status == 0)
    {
        printf("\n%sNow Playing:\n", GREEN);
        printf("%sNo songs have been played yet. Please search for a song to begin playback.\n", WHITE);

        printf("\n%sQueue:\n", GREEN);
        printf("%sYour queue is empty.\n", WHITE);
    }
    else if ((*CS).status == 1 && ((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF))
    {
        printf("\n%sNow Playing:\n", GREEN);
        printf("%s%s - %s - %s\n", WHITE, (*CS).NamaPenyanyi.TabLine, (*CS).JudulLagu.TabLine, (*CS).NamaAlbum.TabLine);

        printf("\n%sQueue:\n", GREEN);
        printf("%sYour queue is empty.\n", WHITE);
    }
    else if ((*CS).status == 1 && ((*QL).idxHead != IDX_UNDEF || (*QL).idxTail != IDX_UNDEF))
    {
        printf("\n%sNow Playing:\n", GREEN);
        printf("%s%s - %s - %s\n", WHITE, (*CS).NamaPenyanyi.TabLine, (*CS).JudulLagu.TabLine, (*CS).NamaAlbum.TabLine);

        printf("\n%sQueue:\n", GREEN);
        for (int i = (*QL).idxHead; i <= (*QL).idxTail; i++)
        {
            printf("%s%d. %s - %s - %s\n", WHITE, i+1, (*QL).NamaPenyanyi[i].TabLine, (*QL).JudulLagu[i].TabLine, (*QL).NamaAlbum[i].TabLine);
        }
    }
}