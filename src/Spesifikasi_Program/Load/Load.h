#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/CharMachine/charmachine.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Queue/queue.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../Queue/Queue.h"
#include "../Playlist/Playlist.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../../ADT/MapSetList/mapsetlist.h"

void LOADFILE(ListPenyanyi * LP, char filename[], QueueLagu * QL, RiwayatLagu * RL, ArrayDin * AP);

#endif