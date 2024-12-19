#include<stdio.h>

void heapify(int* arr, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to implement Heap Sort
void heapSort(int* arr, int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



int main(){
	int right_list[] = {88276,66898,58877,69396,53434,69841,51135,75350,87528,33533,88767,70018,25424,46726,41136,81001,48800,68425,32161,18867,58177,67114,48598,49215,50571,57798,87680,81941,25776,61540,30036,72011,74083,87228,49402,20185,79992,83744,51270,65194,83619,61729,22798,17489,72632,20376,14663,75764,42214,73812,77490,58694,84894,89172,26728,38031,42918,71012,54495,46702,43028,35521,67868,34274,20784,35595,34154,44840,36669,41986,46387,44020,84238,36022,71031,64368,10793,20169,18550,88728,66508,18159,39451,42664,23446,97584,78504,26535,15557,28271,36597,46447,95598,93731,32397,52807,26220,95837,67607,37466,43058,26473,68777,22436,88573,61259,38254,93975,57986,77318,84495,81381,57739,60598,33182,93710,37609,78984,22162,55715,63919,90630,25719,94542,46758,81729,38275,98915,56501,26391,20345,90235,76165,34771,11831,17735,82093,74646,18879,62123,76704,35340,17626,73828,60131,93584,62201,19005,35018,47795,41800,80773,80820,22857,37449,82183,45864,36815,54020,81545,62572,44708,66801,59501,67098,21266,58508,84719,45950,70627,94298,11607,99117,17953,31425,85902,88524,63952,19191,79802,57866,62302,78098,20698,84629,41677,27485,75935,31977,10336,38958,84834,96511,12736,89758,53646,15153,32060,27908,16393,25261,60760,25775,16904,62346,47080,93255,89013,43284,65144,48707,57437,11138,24856,29683,98693,77263,30391,33113,65000,31396,46020,99476,11386,13977,86041,62608,80461,42619,18929,91858,19069,61625,13273,58290,31333,95844,29334,24222,76497,47981,81211,43664,74273,45398,98433,26920,27584,63319,54868,43366,71718,83801,61400,61109,95577,27710,68618,14815,99140,19676,66372,44319,73785,67363,37981,64109,38227,50207,15814,35531,87819,77349,53298,93233,39520,12419,60177,75199,56305,32449,34934,27633,41294,34059,55758,95114,73343,58117,10949,50109,83134,42282,98859,77195,68363,27138,54907,48273,54605,62553,17301,21589,96728,17529,89541,51908,29216,37748,38967,25027,37822,16972,65654,89175,92617,83877,44697,66651,78880,37397,95633,43655,64537,40450,35026,50317,36367,72620,92261,65227,55208,75345,42971,23437,67508,30045,26319,94064,82690,72650,50246,43186,95740,93191,18379,88847,93995,29163,14073,58056,38419,72129,60430,53216,26547,83079,93135,77493,12140,95863,95009,54331,41336,28390,30001,16467,41976,72803,13293,81616,55833,56308,37379,82304,25192,61301,50596,89256,51767,99750,73773,55989,97758,10410,53668,77104,68379,77163,28265,90246,16607,96931,58164,73496,48229,45012,66692,37875,46075,48894,99826,14013,71154,66577,36276,19745,50165,38691,95886,52404,29053,54601,78577,88081,22120,26351,65154,94729,24835,47235,73145,36917,20883,52413,34176,63332,31710,71774,85579,41953,97551,71600,59341,31814,95286,76385,55251,90169,29732,13303,72252,17173,28700,17812,53025,59430,12042,58967,85014,46781,39766,73197,90285,79561,20685,76311,79752,43455,20101,40723,99036,15360,83359,24092,74245,78493,18109,33181,30810,49318,48376,66515,85559,52603,15485,96967,82449,15134,77060,15232,84525,78813,94671,42843,74833,66138,76441,48947,40084,39507,22913,57276,58685,79898,31508,81103,22402,20796,12508,15845,13737,44058,50103,96114,77456,11099,55100,66890,34647,89464,59790,66352,22083,50907,53119,63810,80195,23998,68579,83066,54633,11848,39398,55018,15490,22818,70014,84784,56723,42172,27501,68628,26910,69452,55377,75773,76624,95112,87646,17801,87295,44500,44268,36127,47954,32935,82874,43736,35398,57240,66137,70642,26664,21077,18083,68347,43546,59969,97915,27970,34897,68826,62321,31006,84746,90395,79681,21845,14083,27976,55683,37310,97078,59224,97516,97794,68947,92999,90600,60922,94745,92352,23167,58643,26061,81562,62234,32629,55857,86338,33959,49952,25710,89653,29597,48607,45503,34827,55026,79004,49530,63035,21467,32990,37155,86903,99869,92845,23477,49028,85415,86639,92362,47938,56412,53250,97330,34681,63641,23187,30279,69161,85026,39547,26347,38232,58398,20322,15669,58858,22292,29471,90339,79941,27230,72115,82786,91405,37597,69470,92310,31838,45720,81126,18163,84101,68690,81944,75593,84103,47576,67268,81782,34915,90879,37594,66147,79839,15112,12908,84519,59355,82078,55861,29250,61882,87566,92451,81915,97640,85815,99849,63018,28370,48533,80523,31016,58468,43628,64414,44240,11713,38810,96131,88407,93559,13946,47619,10982,11173,90206,92293,76729,43385,21688,34259,89157,57155,24597,74759,78307,39986,27292,16156,63506,31033,37996,62762,16153,52242,15408,62161,83394,41640,81262,63439,56270,70128,14772,49672,65463,36553,91426,87810,60238,25042,24118,89578,12535,98679,66756,32315,54236,57742,88687,27546,38444,54413,61066,50625,64691,14588,82277,86045,10805,26418,33509,92241,16301,33262,63819,60290,27878,62757,33736,54632,98296,40338,39847,68719,26251,31242,17968,65814,87166,66068,63451,75377,76019,31860,16990,68237,97234,10354,90915,57030,46774,98324,62884,69753,40694,29722,82408,78426,36510,82646,60802,22506,41287,70889,42747,63269,94305,83292,99601,28090,75509,72603,83377,60842,75682,22941,17444,74802,14072,87701,34656,46875,27302,48261,76463,82028,73870,61202,42408,35464,70524,82046,36533,57066,46809,68136,96003,91179,48169,66757,13487,31943,30614,49160,73079,48309,37764,69645,73753,40007,28731,52577,24804,45279,50104,58957,74242,82526,53224,28710,16639,35975,69003,32252,45703,43201,69422,28861,96176,59974,41775,28765,68451,70833,91438,14337,92555,82354,91403,36010,71745,76896,80599,68209,37710,93904,30193,41556,66899,94568,54705,81380,34483,65507,30120,29450,42736,53346,14757,40165,79668,41837,84503,20697,25413,42745,20196,46639,20938,72750,30633,69800,15331,70263,45791,82870,19018,51852,27414,34329,92239,84367,77053,22196,85126,47732,61744,98222,97357,70811,16481,43767,35217,61111,12172,73660,86799,81356,11180,63364,56016,36532,50093,49544,77019,48935,59500,84514,10182,84993,32090,52538,44305,35273,82847,14193,12518,30971,63688,92997,84824,61855,54244,21885,69802,84492,72691,88759,14184,80558,52320,72459,35029,95586,20863,88115,66836,77227,45790,78529,24755,66458,88377,89711,19124,34822,22669,13714,34557,82299,29716,75280,57005,13298,23203,99989,33132,22248,54269,52385,16123,41031,61081,16985,50927,49258,51058,12476,41318,20691,22660,76815,36438};
	int left_list[] = {66757,13714,87487,12997,62485,67231,99904,18379,59461,35866,25688,18379,37382,68550,44070,57100,20883,87909,69003,53216,19563,46700,90768,39678,65700,56585,69003,15557,32379,58056,13872,69003,56426,81833,73309,37731,61292,53216,88596,46832,84894,48656,27189,88767,85830,74164,10793,18838,79141,70018,16156,13273,57554,61675,10793,20716,72362,67914,54567,63623,14772,30594,67268,24937,48924,84894,24579,59881,56576,66757,17065,21738,17801,30633,18379,17801,84894,34934,70811,62854,64049,54705,58284,38958,75653,43691,58006,53216,21045,47020,50514,13273,22815,81772,42899,58056,59055,54705,97159,45429,45549,38665,98333,91327,18379,13273,22391,44919,86639,62161,36775,69003,16156,40116,57284,40019,19836,38227,87784,79073,45370,87468,18379,80660,65583,67887,92261,65294,83143,18379,88767,72889,65757,17801,85257,15601,80861,34915,15331,90282,10793,46892,57504,23294,44363,10793,44764,87646,42747,36954,78433,85010,34934,81640,10995,24232,46505,48985,13273,88831,18336,64739,97842,12794,75382,53216,43409,20883,65647,47730,87646,88003,20883,13714,86162,88767,97877,35026,38958,15331,56895,46538,95481,43965,80543,21616,27525,45791,16820,78794,13714,61769,44057,28591,59184,54868,91337,34232,45791,78168,52734,38227,20883,29227,53147,42526,70760,13714,69177,93383,87646,58056,75483,38227,60040,55209,69834,66757,47463,34934,62769,54868,85419,68175,58056,38227,84894,68879,35285,71805,28002,58965,39986,26273,17801,73406,13714,65412,38958,34934,89514,34934,54868,56326,62234,24775,45683,53650,34934,94619,21445,67268,64077,87482,73784,95495,62470,60416,48005,22460,93554,67268,54705,38227,93256,18379,73147,20524,32773,34934,51496,40501,59926,53216,89273,53090,18379,30633,20883,61815,20883,92261,70811,76937,83935,53216,20883,17801,34990,96230,62234,69003,73755,16156,34936,70641,56932,69003,34963,38227,53216,70286,53216,66836,35032,25694,91737,88253,45791,87646,17801,70633,67268,34934,95938,45000,83146,90064,38099,82635,39515,50909,21622,89934,87646,13138,65063,26063,55251,88897,38227,18379,90329,21974,67268,18379,16156,27240,38227,76351,67139,22712,15747,20883,13714,83628,15557,58056,63382,83041,28252,50517,36822,16927,85921,13714,62059,19940,16156,39266,62615,62234,24152,16156,19287,15504,53692,83571,87214,10867,64934,82155,56036,88011,45791,91524,79890,22365,17501,58056,82991,58056,92694,54705,66836,15557,98199,93700,45791,83674,87646,53216,10986,69003,26903,87646,92261,73386,67293,58056,16156,28966,13714,75281,52658,67971,67976,16045,39831,24698,53216,41597,58906,47079,48581,68666,62161,38227,14427,54705,67268,32949,15557,84370,13273,16318,34982,67268,39986,81359,47411,35053,37157,10793,20883,28138,70018,30633,38227,99935,49689,88468,58056,70149,87646,85815,39986,87646,13714,67196,35030,17397,13714,37175,77643,38227,44446,59320,38958,54705,99694,70018,54965,12873,54868,71718,62161,55721,59369,19435,94743,62161,87414,15557,44720,20883,27019,12132,15557,87646,30633,81344,58056,35026,99195,49878,57461,78545,16156,46125,31266,92912,34580,89739,91562,38958,18379,53216,81856,83048,58056,53216,35703,42524,18379,54868,66757,93538,28815,20001,88767,54705,58056,35759,38958,44593,43558,52839,80406,58056,86161,62161,45107,30633,58056,11285,95835,28867,57746,65352,87903,86600,91343,91216,34934,84894,23086,92261,61352,75410,88973,24188,71189,79027,34510,81842,64378,36571,81253,70328,38596,79284,82128,92184,11347,89605,85815,38958,30633,89890,16300,96640,76961,88767,76074,15053,63856,67268,48545,20504,29312,66305,34934,16156,10730,36549,66592,10793,97170,66144,28741,79303,40342,59932,88767,66757,67268,32838,78332,18379,71709,58121,51180,92469,71788,16156,87881,54705,16156,94098,34934,95083,28344,54751,34915,34934,55251,10108,47298,60183,56651,68503,15557,38227,34915,12304,75369,76347,91259,90665,58997,71718,67268,63209,34932,30633,39986,76836,33664,20883,98658,13714,20883,49702,49173,84894,63029,84894,80172,67268,31565,34934,29399,89342,29470,93980,30633,15557,16156,91824,15557,73920,20560,20731,99203,87413,36392,68848,70811,56365,39986,10676,62234,62008,47549,34934,50287,54557,60436,47513,19090,17801,47705,91614,55251,86597,34459,59020,54705,70018,80703,34915,84894,71311,35026,10936,85865,26160,18379,83917,70811,66757,88623,18379,15557,32112,85603,66836,10498,39986,69825,34934,43335,81803,85627,13714,14568,41539,67268,88612,84125,49872,38958,10793,80576,38958,54311,18379,66836,88767,85815,43259,45228,85016,84894,91756,30633,20883,59592,28169,54868,13714,60740,16156,82952,30613,11813,39309,56057,67268,68918,55378,56691,37006,84894,57086,67268,60476,66836,86823,10793,52670,10793,53216,98193,34915,87646,43032,67268,41598,18379,33052,69560,56471,53535,25880,54868,88767,41062,55251,12486,16698,18379,66836,66836,87646,58056,54705,53216,53216,66391,13975,13273,55251,58056,38227,67268,87646,66757,15557,66836,67268,90043,82436,22670,39551,66757,41388,75763,27121,29742,69003,91520,96589,74511,22164,16156,38958,55251,96310,18379,18379,62161,40972,55251,53216,98985,58056,15557,67481,23899,62234,20883,77821,95184,34915,59886,16156,86757,70811,70309,39722,37895,71680,37598,45296,70018,65261,81921,16156,98310,87161,38666,18712,81245,62161,65636,38227,41678,35735,61054,27344,66152,11795,13714,25321,64702,15018,63103,88767,53291,85815,26868,72661,83663,27206,53118,70672,44797,13649,27383,98935,82659,42747,54705,17801,67268,54705,38382,91559,15462,99282,30633,25981,20223,13261,24578,30274,30633,41456,22277,30633,27488,25861,37155,62045,54705,88177,53727,73432,84538,36671,97037,13504,36396,84869,56409,59556,37071,63830,48976,31004,10793,34934,54705,50118,34934,50585,24227,61159,62161,98529,54705,56295,16570,80373,92261,17801,99212,54344,57185,34915,20883,47386,72550,25351,85337,55251,53216,94306,84894,74140,33678,12093,80895,47385,87012,54652,58056,45791,92261,29445,19896,45791,80738,51249,90751,36978,54705,92752,27377,97024,34934,61708,55251,58056,53216,35026,73956,72500,62749,19344,18299,54705,85665,15331,87216,79261,13714,66540,92583,15204,67268,98670,92416,95004,61354,23411,71595,64062,96641,69003,86025,58056,34934,43346,25148,17801,26086,47508};

	int right_size = sizeof(right_list)/sizeof(int);
	int left_size = sizeof(left_list)/sizeof(int);

	//sorting the array
	heapSort(right_list,right_size);
	heapSort(left_list,left_size);
	
	//finding the sum
	int final_solution = 0;
	for(int i = 0;i < right_size;i++){
		if(right_list[i] > left_list[i]){
			final_solution += right_list[i] - left_list[i];
		}
		else{
			final_solution += left_list[i] - right_list[i];
		}
	}
	printf("%d",final_solution);

	return 0;
}
