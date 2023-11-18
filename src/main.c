/* *** ******** ******** ******** ******** ******** ****** *** *** ANGGOTA KELOMPOK *** *** ****** ******** ******** ******** ******** ******** *** */

                                                        /* 18222118 Rizqi Andhika Pratama  */
                                                        /* 18222107 Lina Azizah R.H.       */
                                                        /* 18222113 Angelica Aliwinata     */
                                                        /* 18222117 Ahmad Fawwazi          */
                                                        /* 18222123 Melissa Trenggono      */
                                                        /* 18222124 Fadian Alif Mahardika  */

/* *** ******** ******** ******** ******** ******** ****** *** LIBRARY YANG DIGUNAKAN *** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>

/* *** ******** ******** ******** ******** ******** ****** *** FILE HEADER ADT *** ****** ******** ******** ******** ******** ******** *** */

#include "ADT/boolean.h"
#include "ADT/Queue/queue.h"
#include "ADT/MapSetList/mapsetlist.h"
#include "ADT/Stack/RiwayatLagu.h"
#include "ADT/LinkedList/linkedlist.h"
#include "ADT/array/arraydinamis.h"
#include "ADT/LineMachine/linemachine.h"

/* *** ******** ******** ******** ******** ******** ****** *** FILE HEADER SPESIFIKASI *** ****** ******** ******** ******** ******** ******** *** */

#include "Spesifikasi_Program/Inisialisasi/inisialisasi.h"
#include "Spesifikasi_Program/List/List.h"
#include "Spesifikasi_Program/Start/start.h"
#include "Spesifikasi_Program/Play/Play.h"
#include "Spesifikasi_Program/Load/Load.h"
#include "Spesifikasi_Program/Queue/Queue.h"
#include "Spesifikasi_Program/Help/help.h"
#include "Spesifikasi_Program/Song/Song.h"
#include "Spesifikasi_Program/Status/Status.h"
#include "Spesifikasi_Program/Playlist/Playlist.h"
#include "Spesifikasi_Program/Save/save.h"
#include "Spesifikasi_Program/Enhance/enhance.h"
#include "Spesifikasi_Program/MultiUser/MultiUser.h"

/* *** ******** ******** ******** ******** ******** ****** *** PROGRAM UTAMA *** ****** ******** ******** ******** ******** ******** *** */
int main()
{   
    // Kondisi Program
    boolean mulai = true;
    boolean sesi = false;

/* *** ******** ******** ******** ******** ******** ****** ** PRINT MAIN MENU ** ****** ******** ******** ******** ******** ******** *** */

    // Print Main Menu
    inisialisasi();

/* *** ******** ******** ******** ******** ******** ****** ** STORAGE WAYANGWAVE ** ****** ******** ******** ******** ******** ******** *** */

    // Kamus

    DataUser DU;
    CreateDataUser(&DU);
    
    ListPenyanyi LP;
    CreateListPenyanyi(&LP);

    CurrentSong CS;
    CreateCurrentSong(&CS);

    QueueLagu QL;
    CreateQueueLagu(&QL);

    RiwayatLagu RL;
    CreateRiwayatLagu(&RL);

    ArrayDin AP = MakeArrayDin();

    Kalimat NamaFile;

/* *** ******** ******** ******** ******** ******** ****** ** MULAI COMMAND ** ****** ******** ******** ******** ******** ******** *** */

    // Meminta Command
    while (mulai)
    {
        printf("%s>> ", WHITE);
        STARTCOMMAND();

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND START ** ****** ******** ******** ******** ******** ******** *** */

        if (isInputEqual(CCommand, "START")){

            if (sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }   
            else
            {
                delay(1);
                printf("\n%s[=========", GREEN);
                delay(1);
                printf("==========");
                delay(1);
                printf("%s Loading WayangWave.. ", CYAN);
                delay(1);
                printf("%s==========", GREEN);
                delay(1);
                printf("=========]\n");          

                STARTREAD(&LP, "Data/config.txt"); // ganti ke config jangan lupa

                printf("\n%sOutput: %sFile konfigurasi aplikasi berhasil dibaca.\n", GREEN, WHITE);

                printf("\n%s[=========", GREEN);
                printf("==========");

                printf("%s WayangWave Running.. ", CYAN);

                printf("%s==========", GREEN);
                printf("=========]\n\n");

                
                sesi = true;
            }
        }
        
    
/* *** ******** ******** ******** ******** ******** ****** ** COMMAND LOAD ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "LOAD"))
        { 
            
            if (!sesi)
            {
                ADVCOMMAND();

                delay(1);
                printf("\n%s[=========", GREEN);
                delay(1);
                printf("==========");
                delay(1);
                printf("%s Loading %s.. ", CYAN, CCommand.TabLine);
                delay(1);
                printf("%s==========", GREEN);
                delay(1);
                printf("=========]\n");

                NamaFile = DirectoryCommand(CCommand);

                LOADFILE(&LP, NamaFile.TabLine, &QL, &RL, &AP, &CS); 

                printf("\n%sOutput: %sFile save berhasil dibaca.\n", GREEN, WHITE);

                printf("\n%s[=========", GREEN);
                printf("==========");

                printf("%s WayangWave Running.. ", CYAN);

                printf("%s==========", GREEN);
                printf("=========]\n\n");

                sesi = true;
            }
            else
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }

        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND LIST ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "LIST")){
            ADVCOMMAND();

            if (isInputEqual(CCommand, "DEFAULT"))
            {

                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    DisplayListDefault(&LP);
                }

            }

            else if (isInputEqual(CCommand, "PLAYLIST"))
            {

                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    displayPlaylist(&AP);
                }

            }

            else
            {
                printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
            }
    
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND PLAY ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "PLAY")){
            ADVCOMMAND();

            if (isInputEqual(CCommand, "SONG"))
            {

                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    PlaySong(&LP, &CS, &QL, &RL);
                }      

            }
            if (isInputEqual(CCommand, "PLAYLIST"))
            {

                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    PlayPlaylist(&AP, &QL, &RL);
                }      

            }
            else
            {
                printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
            }
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND QUEUE ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "QUEUE")){
            ADVCOMMAND();

            if (isInputEqual(CCommand, "SONG"))
            {

                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {   
                    QueueAddLagu(&LP, &QL, &CS);
                }      

            }

            else if (isInputEqual(CCommand, "REMOVE"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {   
                ADVCOMMAND();
                int idQueue = CCommand.TabLine[0] - 48;

                QueueRemoveLagu(&QL, &RL, idQueue);
                }
            }

            else if (isInputEqual(CCommand, "SWAP"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {   
                ADVCOMMAND();

                int id1 = atoi(CCommand.TabLine);

                ADVCOMMAND();

                int id2 = atoi(CCommand.TabLine);

                QueueSwap(&QL, id1, id2);
                }

            }

            else if (isInputEqual(CCommand, "PLAYLIST"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {   
                    QueuePlaylist(&AP, &QL, &CS);
                }
            }

            else if (isInputEqual(CCommand, "CLEAR"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {   
                    QueueClear(&QL);
                }
            }

            else
            {
                printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
            }
       
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SONG ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "SONG")){
            ADVCOMMAND();

            if (isInputEqual(CCommand, "NEXT"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    SongNext(&QL, &RL, &CS);
                }
            }

            else if (isInputEqual(CCommand, "PREVIOUS"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    SongPrev(&QL, &RL, &CS);
                }
            }

            else
            {
                printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
            }
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND PLAYLIST ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "PLAYLIST")){
            ADVCOMMAND();

            if (isInputEqual(CCommand, "CREATE"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    PlaylistCreate(&AP);
                }
            }

            else if (isInputEqual(CCommand, "ADD"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    ADVCOMMAND();

                    if (isInputEqual(CCommand, "SONG"))
                    {   
                        PlaylistAddLagu(&AP, &LP);
                    }
                    else if (isInputEqual(CCommand, "ALBUM"))
                    {   
                        PlaylistAddAlbum(&AP, &LP);
                    }

                }
            }

            else if (isInputEqual(CCommand, "REMOVE"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    ADVCOMMAND();
                    int idPlaylist = atoi(CCommand.TabLine);

                    ADVCOMMAND();
                    int idLagu = atoi(CCommand.TabLine);

                    PlayListRemoveLagu(&AP, idPlaylist, idLagu);
                }
            }

            else if (isInputEqual(CCommand, "SWAP"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    ADVCOMMAND();
                    int idPlaylist = atoi(CCommand.TabLine) - 1;

                    ADVCOMMAND();
                    int idLagu1 = atoi(CCommand.TabLine) - 1;

                    ADVCOMMAND();
                    int idLagu2 = atoi(CCommand.TabLine) - 1;

                    // printf("%d\n", idLagu1);
                    // printf("%d\n", idLagu2);

                    playlistSwap(&AP, idPlaylist, idLagu1, idLagu2);
                }
            }

            else if (isInputEqual(CCommand, "DELETE"))
            {   
                if (!sesi)
                {
                    printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
                }
                else
                {
                    deletePlaylist(&AP);
                }
            }

            else
            {
                printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
            }
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND ENHANCE ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "ENHANCE"))
        {

            if (!sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }
            else
            {
                EnchancePL(&LP, &AP);
            }

        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND STATUS ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "STATUS")){

            if (!sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }
            else
            {   
                // printf("%d\n", (CS).status);
                Status(&CS, &QL);
            }
            
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SAVE ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "SAVE")){
            ADVCOMMAND();

            if (!sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }
            else
            {

                delay(1);
                printf("\n%s[=========", GREEN);
                delay(1);
                printf("==========");
                delay(1);
                printf("%s Saving to %s.. ", CYAN, CCommand.TabLine);
                delay(1);
                printf("%s==========", GREEN);
                delay(1);
                printf("=========]\n");     

                CCommand = DirectoryCommand(CCommand);     

                SaveFile(&LP,&AP, &QL, &RL, &CS, CCommand.TabLine);

                printf("\n%sOutput: %sProgram berhasil disave!.\n", GREEN, WHITE);

                printf("\n%s[=========", GREEN);
                printf("==========");

                printf("%s WayangWave Saved.. ", CYAN);

                printf("%s==========", GREEN);
                printf("=========]\n\n");

            }
        }


/* *** ******** ******** ******** ******** ******** ****** ** COMMAND HELP ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "HELP")){

            help(sesi);
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND QUIT ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CCommand, "QUIT")){
            
            printf("\n%sApakah kamu ingin menyimpan data sesi sekarang? %s", GREEN, WHITE);
            STARTCOMMAND();

            if (CCommand.TabLine[0] == 'Y')
            {
                SaveFile(&LP, &AP, &QL, &RL, &CS, NamaFile.TabLine);
            }

            delay(1);
            printf("\n%s[=========", GREEN);
            delay(1);
            printf("==========");
            printf("%s Logging Out.. ", CYAN);
            printf("%s==========", GREEN);
            delay(1);
            printf("=========]\n");
            delay(1);

            printf("\n%sOutput: %sKamu keluar dari %sWayangWave.\n", GREEN, WHITE, GREEN);
            printf("%sDadah ^_^/\n", WHITE);

            printf("\n%s[=========", GREEN);
            printf("==========");
            printf("%s  Logged Out!  ", CYAN);
            printf("%s==========", GREEN);
            printf("=========]\n\n");

            mulai = false;
            
        }
        
/* *** ******** ******** ******** ******** ******** ****** ** INVALID COMMAND ** ****** ******** ******** ******** ******** ******** *** */

        else
        {
            printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
        }

        printf("%s--------------------------------------------------------------------------------------------------------------\n", GREEN);
    
    }

    return 0;
}
