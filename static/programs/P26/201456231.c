#include<stdio.h>
#include<stdlib.h>
#define push(val) queue[end++]=val;
#define pop() queue[start++]

long long int i,j,size_nos,l,val[1111],a[1111][1111],size[1111];

void prime()
{
val[0]=1009;
val[1]=1013;
val[2]=1019;
val[3]=1021;
val[4]=1031;
val[5]=1033;
val[6]=1039;
val[7]=1049;
val[8]=1051;
val[9]=1061;
val[10]=1063;
val[11]=1069;
val[12]=1087;
val[13]=1091;
val[14]=1093;
val[15]=1097;
val[16]=1103;
val[17]=1109;
val[18]=1117;
val[19]=1123;
val[20]=1129;
val[21]=1151;
val[22]=1153;
val[23]=1163;
val[24]=1171;
val[25]=1181;
val[26]=1187;
val[27]=1193;
val[28]=1201;
val[29]=1213;
val[30]=1217;
val[31]=1223;
val[32]=1229;
val[33]=1231;
val[34]=1237;
val[35]=1249;
val[36]=1259;
val[37]=1277;
val[38]=1279;
val[39]=1283;
val[40]=1289;
val[41]=1291;
val[42]=1297;
val[43]=1301;
val[44]=1303;
val[45]=1307;
val[46]=1319;
val[47]=1321;
val[48]=1327;
val[49]=1361;
val[50]=1367;
val[51]=1373;
val[52]=1381;
val[53]=1399;
val[54]=1409;
val[55]=1423;
val[56]=1427;
val[57]=1429;
val[58]=1433;
val[59]=1439;
val[60]=1447;
val[61]=1451;
val[62]=1453;
val[63]=1459;
val[64]=1471;
val[65]=1481;
val[66]=1483;
val[67]=1487;
val[68]=1489;
val[69]=1493;
val[70]=1499;
val[71]=1511;
val[72]=1523;
val[73]=1531;
val[74]=1543;
val[75]=1549;
val[76]=1553;
val[77]=1559;
val[78]=1567;
val[79]=1571;
val[80]=1579;
val[81]=1583;
val[82]=1597;
val[83]=1601;
val[84]=1607;
val[85]=1609;
val[86]=1613;
val[87]=1619;
val[88]=1621;
val[89]=1627;
val[90]=1637;
val[91]=1657;
val[92]=1663;
val[93]=1667;
val[94]=1669;
val[95]=1693;
val[96]=1697;
val[97]=1699;
val[98]=1709;
val[99]=1721;
val[100]=1723;
val[101]=1733;
val[102]=1741;
val[103]=1747;
val[104]=1753;
val[105]=1759;
val[106]=1777;
val[107]=1783;
val[108]=1787;
val[109]=1789;
val[110]=1801;
val[111]=1811;
val[112]=1823;
val[113]=1831;
val[114]=1847;
val[115]=1861;
val[116]=1867;
val[117]=1871;
val[118]=1873;
val[119]=1877;
val[120]=1879;
val[121]=1889;
val[122]=1901;
val[123]=1907;
val[124]=1913;
val[125]=1931;
val[126]=1933;
val[127]=1949;
val[128]=1951;
val[129]=1973;
val[130]=1979;
val[131]=1987;
val[132]=1993;
val[133]=1997;
val[134]=1999;
val[135]=2003;
val[136]=2011;
val[137]=2017;
val[138]=2027;
val[139]=2029;
val[140]=2039;
val[141]=2053;
val[142]=2063;
val[143]=2069;
val[144]=2081;
val[145]=2083;
val[146]=2087;
val[147]=2089;
val[148]=2099;
val[149]=2111;
val[150]=2113;
val[151]=2129;
val[152]=2131;
val[153]=2137;
val[154]=2141;
val[155]=2143;
val[156]=2153;
val[157]=2161;
val[158]=2179;
val[159]=2203;
val[160]=2207;
val[161]=2213;
val[162]=2221;
val[163]=2237;
val[164]=2239;
val[165]=2243;
val[166]=2251;
val[167]=2267;
val[168]=2269;
val[169]=2273;
val[170]=2281;
val[171]=2287;
val[172]=2293;
val[173]=2297;
val[174]=2309;
val[175]=2311;
val[176]=2333;
val[177]=2339;
val[178]=2341;
val[179]=2347;
val[180]=2351;
val[181]=2357;
val[182]=2371;
val[183]=2377;
val[184]=2381;
val[185]=2383;
val[186]=2389;
val[187]=2393;
val[188]=2399;
val[189]=2411;
val[190]=2417;
val[191]=2423;
val[192]=2437;
val[193]=2441;
val[194]=2447;
val[195]=2459;
val[196]=2467;
val[197]=2473;
val[198]=2477;
val[199]=2503;
val[200]=2521;
val[201]=2531;
val[202]=2539;
val[203]=2543;
val[204]=2549;
val[205]=2551;
val[206]=2557;
val[207]=2579;
val[208]=2591;
val[209]=2593;
val[210]=2609;
val[211]=2617;
val[212]=2621;
val[213]=2633;
val[214]=2647;
val[215]=2657;
val[216]=2659;
val[217]=2663;
val[218]=2671;
val[219]=2677;
val[220]=2683;
val[221]=2687;
val[222]=2689;
val[223]=2693;
val[224]=2699;
val[225]=2707;
val[226]=2711;
val[227]=2713;
val[228]=2719;
val[229]=2729;
val[230]=2731;
val[231]=2741;
val[232]=2749;
val[233]=2753;
val[234]=2767;
val[235]=2777;
val[236]=2789;
val[237]=2791;
val[238]=2797;
val[239]=2801;
val[240]=2803;
val[241]=2819;
val[242]=2833;
val[243]=2837;
val[244]=2843;
val[245]=2851;
val[246]=2857;
val[247]=2861;
val[248]=2879;
val[249]=2887;
val[250]=2897;
val[251]=2903;
val[252]=2909;
val[253]=2917;
val[254]=2927;
val[255]=2939;
val[256]=2953;
val[257]=2957;
val[258]=2963;
val[259]=2969;
val[260]=2971;
val[261]=2999;
val[262]=3001;
val[263]=3011;
val[264]=3019;
val[265]=3023;
val[266]=3037;
val[267]=3041;
val[268]=3049;
val[269]=3061;
val[270]=3067;
val[271]=3079;
val[272]=3083;
val[273]=3089;
val[274]=3109;
val[275]=3119;
val[276]=3121;
val[277]=3137;
val[278]=3163;
val[279]=3167;
val[280]=3169;
val[281]=3181;
val[282]=3187;
val[283]=3191;
val[284]=3203;
val[285]=3209;
val[286]=3217;
val[287]=3221;
val[288]=3229;
val[289]=3251;
val[290]=3253;
val[291]=3257;
val[292]=3259;
val[293]=3271;
val[294]=3299;
val[295]=3301;
val[296]=3307;
val[297]=3313;
val[298]=3319;
val[299]=3323;
val[300]=3329;
val[301]=3331;
val[302]=3343;
val[303]=3347;
val[304]=3359;
val[305]=3361;
val[306]=3371;
val[307]=3373;
val[308]=3389;
val[309]=3391;
val[310]=3407;
val[311]=3413;
val[312]=3433;
val[313]=3449;
val[314]=3457;
val[315]=3461;
val[316]=3463;
val[317]=3467;
val[318]=3469;
val[319]=3491;
val[320]=3499;
val[321]=3511;
val[322]=3517;
val[323]=3527;
val[324]=3529;
val[325]=3533;
val[326]=3539;
val[327]=3541;
val[328]=3547;
val[329]=3557;
val[330]=3559;
val[331]=3571;
val[332]=3581;
val[333]=3583;
val[334]=3593;
val[335]=3607;
val[336]=3613;
val[337]=3617;
val[338]=3623;
val[339]=3631;
val[340]=3637;
val[341]=3643;
val[342]=3659;
val[343]=3671;
val[344]=3673;
val[345]=3677;
val[346]=3691;
val[347]=3697;
val[348]=3701;
val[349]=3709;
val[350]=3719;
val[351]=3727;
val[352]=3733;
val[353]=3739;
val[354]=3761;
val[355]=3767;
val[356]=3769;
val[357]=3779;
val[358]=3793;
val[359]=3797;
val[360]=3803;
val[361]=3821;
val[362]=3823;
val[363]=3833;
val[364]=3847;
val[365]=3851;
val[366]=3853;
val[367]=3863;
val[368]=3877;
val[369]=3881;
val[370]=3889;
val[371]=3907;
val[372]=3911;
val[373]=3917;
val[374]=3919;
val[375]=3923;
val[376]=3929;
val[377]=3931;
val[378]=3943;
val[379]=3947;
val[380]=3967;
val[381]=3989;
val[382]=4001;
val[383]=4003;
val[384]=4007;
val[385]=4013;
val[386]=4019;
val[387]=4021;
val[388]=4027;
val[389]=4049;
val[390]=4051;
val[391]=4057;
val[392]=4073;
val[393]=4079;
val[394]=4091;
val[395]=4093;
val[396]=4099;
val[397]=4111;
val[398]=4127;
val[399]=4129;
val[400]=4133;
val[401]=4139;
val[402]=4153;
val[403]=4157;
val[404]=4159;
val[405]=4177;
val[406]=4201;
val[407]=4211;
val[408]=4217;
val[409]=4219;
val[410]=4229;
val[411]=4231;
val[412]=4241;
val[413]=4243;
val[414]=4253;
val[415]=4259;
val[416]=4261;
val[417]=4271;
val[418]=4273;
val[419]=4283;
val[420]=4289;
val[421]=4297;
val[422]=4327;
val[423]=4337;
val[424]=4339;
val[425]=4349;
val[426]=4357;
val[427]=4363;
val[428]=4373;
val[429]=4391;
val[430]=4397;
val[431]=4409;
val[432]=4421;
val[433]=4423;
val[434]=4441;
val[435]=4447;
val[436]=4451;
val[437]=4457;
val[438]=4463;
val[439]=4481;
val[440]=4483;
val[441]=4493;
val[442]=4507;
val[443]=4513;
val[444]=4517;
val[445]=4519;
val[446]=4523;
val[447]=4547;
val[448]=4549;
val[449]=4561;
val[450]=4567;
val[451]=4583;
val[452]=4591;
val[453]=4597;
val[454]=4603;
val[455]=4621;
val[456]=4637;
val[457]=4639;
val[458]=4643;
val[459]=4649;
val[460]=4651;
val[461]=4657;
val[462]=4663;
val[463]=4673;
val[464]=4679;
val[465]=4691;
val[466]=4703;
val[467]=4721;
val[468]=4723;
val[469]=4729;
val[470]=4733;
val[471]=4751;
val[472]=4759;
val[473]=4783;
val[474]=4787;
val[475]=4789;
val[476]=4793;
val[477]=4799;
val[478]=4801;
val[479]=4813;
val[480]=4817;
val[481]=4831;
val[482]=4861;
val[483]=4871;
val[484]=4877;
val[485]=4889;
val[486]=4903;
val[487]=4909;
val[488]=4919;
val[489]=4931;
val[490]=4933;
val[491]=4937;
val[492]=4943;
val[493]=4951;
val[494]=4957;
val[495]=4967;
val[496]=4969;
val[497]=4973;
val[498]=4987;
val[499]=4993;
val[500]=4999;
val[501]=5003;
val[502]=5009;
val[503]=5011;
val[504]=5021;
val[505]=5023;
val[506]=5039;
val[507]=5051;
val[508]=5059;
val[509]=5077;
val[510]=5081;
val[511]=5087;
val[512]=5099;
val[513]=5101;
val[514]=5107;
val[515]=5113;
val[516]=5119;
val[517]=5147;
val[518]=5153;
val[519]=5167;
val[520]=5171;
val[521]=5179;
val[522]=5189;
val[523]=5197;
val[524]=5209;
val[525]=5227;
val[526]=5231;
val[527]=5233;
val[528]=5237;
val[529]=5261;
val[530]=5273;
val[531]=5279;
val[532]=5281;
val[533]=5297;
val[534]=5303;
val[535]=5309;
val[536]=5323;
val[537]=5333;
val[538]=5347;
val[539]=5351;
val[540]=5381;
val[541]=5387;
val[542]=5393;
val[543]=5399;
val[544]=5407;
val[545]=5413;
val[546]=5417;
val[547]=5419;
val[548]=5431;
val[549]=5437;
val[550]=5441;
val[551]=5443;
val[552]=5449;
val[553]=5471;
val[554]=5477;
val[555]=5479;
val[556]=5483;
val[557]=5501;
val[558]=5503;
val[559]=5507;
val[560]=5519;
val[561]=5521;
val[562]=5527;
val[563]=5531;
val[564]=5557;
val[565]=5563;
val[566]=5569;
val[567]=5573;
val[568]=5581;
val[569]=5591;
val[570]=5623;
val[571]=5639;
val[572]=5641;
val[573]=5647;
val[574]=5651;
val[575]=5653;
val[576]=5657;
val[577]=5659;
val[578]=5669;
val[579]=5683;
val[580]=5689;
val[581]=5693;
val[582]=5701;
val[583]=5711;
val[584]=5717;
val[585]=5737;
val[586]=5741;
val[587]=5743;
val[588]=5749;
val[589]=5779;
val[590]=5783;
val[591]=5791;
val[592]=5801;
val[593]=5807;
val[594]=5813;
val[595]=5821;
val[596]=5827;
val[597]=5839;
val[598]=5843;
val[599]=5849;
val[600]=5851;
val[601]=5857;
val[602]=5861;
val[603]=5867;
val[604]=5869;
val[605]=5879;
val[606]=5881;
val[607]=5897;
val[608]=5903;
val[609]=5923;
val[610]=5927;
val[611]=5939;
val[612]=5953;
val[613]=5981;
val[614]=5987;
val[615]=6007;
val[616]=6011;
val[617]=6029;
val[618]=6037;
val[619]=6043;
val[620]=6047;
val[621]=6053;
val[622]=6067;
val[623]=6073;
val[624]=6079;
val[625]=6089;
val[626]=6091;
val[627]=6101;
val[628]=6113;
val[629]=6121;
val[630]=6131;
val[631]=6133;
val[632]=6143;
val[633]=6151;
val[634]=6163;
val[635]=6173;
val[636]=6197;
val[637]=6199;
val[638]=6203;
val[639]=6211;
val[640]=6217;
val[641]=6221;
val[642]=6229;
val[643]=6247;
val[644]=6257;
val[645]=6263;
val[646]=6269;
val[647]=6271;
val[648]=6277;
val[649]=6287;
val[650]=6299;
val[651]=6301;
val[652]=6311;
val[653]=6317;
val[654]=6323;
val[655]=6329;
val[656]=6337;
val[657]=6343;
val[658]=6353;
val[659]=6359;
val[660]=6361;
val[661]=6367;
val[662]=6373;
val[663]=6379;
val[664]=6389;
val[665]=6397;
val[666]=6421;
val[667]=6427;
val[668]=6449;
val[669]=6451;
val[670]=6469;
val[671]=6473;
val[672]=6481;
val[673]=6491;
val[674]=6521;
val[675]=6529;
val[676]=6547;
val[677]=6551;
val[678]=6553;
val[679]=6563;
val[680]=6569;
val[681]=6571;
val[682]=6577;
val[683]=6581;
val[684]=6599;
val[685]=6607;
val[686]=6619;
val[687]=6637;
val[688]=6653;
val[689]=6659;
val[690]=6661;
val[691]=6673;
val[692]=6679;
val[693]=6689;
val[694]=6691;
val[695]=6701;
val[696]=6703;
val[697]=6709;
val[698]=6719;
val[699]=6733;
val[700]=6737;
val[701]=6761;
val[702]=6763;
val[703]=6779;
val[704]=6781;
val[705]=6791;
val[706]=6793;
val[707]=6803;
val[708]=6823;
val[709]=6827;
val[710]=6829;
val[711]=6833;
val[712]=6841;
val[713]=6857;
val[714]=6863;
val[715]=6869;
val[716]=6871;
val[717]=6883;
val[718]=6899;
val[719]=6907;
val[720]=6911;
val[721]=6917;
val[722]=6947;
val[723]=6949;
val[724]=6959;
val[725]=6961;
val[726]=6967;
val[727]=6971;
val[728]=6977;
val[729]=6983;
val[730]=6991;
val[731]=6997;
val[732]=7001;
val[733]=7013;
val[734]=7019;
val[735]=7027;
val[736]=7039;
val[737]=7043;
val[738]=7057;
val[739]=7069;
val[740]=7079;
val[741]=7103;
val[742]=7109;
val[743]=7121;
val[744]=7127;
val[745]=7129;
val[746]=7151;
val[747]=7159;
val[748]=7177;
val[749]=7187;
val[750]=7193;
val[751]=7207;
val[752]=7211;
val[753]=7213;
val[754]=7219;
val[755]=7229;
val[756]=7237;
val[757]=7243;
val[758]=7247;
val[759]=7253;
val[760]=7283;
val[761]=7297;
val[762]=7307;
val[763]=7309;
val[764]=7321;
val[765]=7331;
val[766]=7333;
val[767]=7349;
val[768]=7351;
val[769]=7369;
val[770]=7393;
val[771]=7411;
val[772]=7417;
val[773]=7433;
val[774]=7451;
val[775]=7457;
val[776]=7459;
val[777]=7477;
val[778]=7481;
val[779]=7487;
val[780]=7489;
val[781]=7499;
val[782]=7507;
val[783]=7517;
val[784]=7523;
val[785]=7529;
val[786]=7537;
val[787]=7541;
val[788]=7547;
val[789]=7549;
val[790]=7559;
val[791]=7561;
val[792]=7573;
val[793]=7577;
val[794]=7583;
val[795]=7589;
val[796]=7591;
val[797]=7603;
val[798]=7607;
val[799]=7621;
val[800]=7639;
val[801]=7643;
val[802]=7649;
val[803]=7669;
val[804]=7673;
val[805]=7681;
val[806]=7687;
val[807]=7691;
val[808]=7699;
val[809]=7703;
val[810]=7717;
val[811]=7723;
val[812]=7727;
val[813]=7741;
val[814]=7753;
val[815]=7757;
val[816]=7759;
val[817]=7789;
val[818]=7793;
val[819]=7817;
val[820]=7823;
val[821]=7829;
val[822]=7841;
val[823]=7853;
val[824]=7867;
val[825]=7873;
val[826]=7877;
val[827]=7879;
val[828]=7883;
val[829]=7901;
val[830]=7907;
val[831]=7919;
val[832]=7927;
val[833]=7933;
val[834]=7937;
val[835]=7949;
val[836]=7951;
val[837]=7963;
val[838]=7993;
val[839]=8009;
val[840]=8011;
val[841]=8017;
val[842]=8039;
val[843]=8053;
val[844]=8059;
val[845]=8069;
val[846]=8081;
val[847]=8087;
val[848]=8089;
val[849]=8093;
val[850]=8101;
val[851]=8111;
val[852]=8117;
val[853]=8123;
val[854]=8147;
val[855]=8161;
val[856]=8167;
val[857]=8171;
val[858]=8179;
val[859]=8191;
val[860]=8209;
val[861]=8219;
val[862]=8221;
val[863]=8231;
val[864]=8233;
val[865]=8237;
val[866]=8243;
val[867]=8263;
val[868]=8269;
val[869]=8273;
val[870]=8287;
val[871]=8291;
val[872]=8293;
val[873]=8297;
val[874]=8311;
val[875]=8317;
val[876]=8329;
val[877]=8353;
val[878]=8363;
val[879]=8369;
val[880]=8377;
val[881]=8387;
val[882]=8389;
val[883]=8419;
val[884]=8423;
val[885]=8429;
val[886]=8431;
val[887]=8443;
val[888]=8447;
val[889]=8461;
val[890]=8467;
val[891]=8501;
val[892]=8513;
val[893]=8521;
val[894]=8527;
val[895]=8537;
val[896]=8539;
val[897]=8543;
val[898]=8563;
val[899]=8573;
val[900]=8581;
val[901]=8597;
val[902]=8599;
val[903]=8609;
val[904]=8623;
val[905]=8627;
val[906]=8629;
val[907]=8641;
val[908]=8647;
val[909]=8663;
val[910]=8669;
val[911]=8677;
val[912]=8681;
val[913]=8689;
val[914]=8693;
val[915]=8699;
val[916]=8707;
val[917]=8713;
val[918]=8719;
val[919]=8731;
val[920]=8737;
val[921]=8741;
val[922]=8747;
val[923]=8753;
val[924]=8761;
val[925]=8779;
val[926]=8783;
val[927]=8803;
val[928]=8807;
val[929]=8819;
val[930]=8821;
val[931]=8831;
val[932]=8837;
val[933]=8839;
val[934]=8849;
val[935]=8861;
val[936]=8863;
val[937]=8867;
val[938]=8887;
val[939]=8893;
val[940]=8923;
val[941]=8929;
val[942]=8933;
val[943]=8941;
val[944]=8951;
val[945]=8963;
val[946]=8969;
val[947]=8971;
val[948]=8999;
val[949]=9001;
val[950]=9007;
val[951]=9011;
val[952]=9013;
val[953]=9029;
val[954]=9041;
val[955]=9043;
val[956]=9049;
val[957]=9059;
val[958]=9067;
val[959]=9091;
val[960]=9103;
val[961]=9109;
val[962]=9127;
val[963]=9133;
val[964]=9137;
val[965]=9151;
val[966]=9157;
val[967]=9161;
val[968]=9173;
val[969]=9181;
val[970]=9187;
val[971]=9199;
val[972]=9203;
val[973]=9209;
val[974]=9221;
val[975]=9227;
val[976]=9239;
val[977]=9241;
val[978]=9257;
val[979]=9277;
val[980]=9281;
val[981]=9283;
val[982]=9293;
val[983]=9311;
val[984]=9319;
val[985]=9323;
val[986]=9337;
val[987]=9341;
val[988]=9343;
val[989]=9349;
val[990]=9371;
val[991]=9377;
val[992]=9391;
val[993]=9397;
val[994]=9403;
val[995]=9413;
val[996]=9419;
val[997]=9421;
val[998]=9431;
val[999]=9433;
val[1000]=9437;
val[1001]=9439;
val[1002]=9461;
val[1003]=9463;
val[1004]=9467;
val[1005]=9473;
val[1006]=9479;
val[1007]=9491;
val[1008]=9497;
val[1009]=9511;
val[1010]=9521;
val[1011]=9533;
val[1012]=9539;
val[1013]=9547;
val[1014]=9551;
val[1015]=9587;
val[1016]=9601;
val[1017]=9613;
val[1018]=9619;
val[1019]=9623;
val[1020]=9629;
val[1021]=9631;
val[1022]=9643;
val[1023]=9649;
val[1024]=9661;
val[1025]=9677;
val[1026]=9679;
val[1027]=9689;
val[1028]=9697;
val[1029]=9719;
val[1030]=9721;
val[1031]=9733;
val[1032]=9739;
val[1033]=9743;
val[1034]=9749;
val[1035]=9767;
val[1036]=9769;
val[1037]=9781;
val[1038]=9787;
val[1039]=9791;
val[1040]=9803;
val[1041]=9811;
val[1042]=9817;
val[1043]=9829;
val[1044]=9833;
val[1045]=9839;
val[1046]=9851;
val[1047]=9857;
val[1048]=9859;
val[1049]=9871;
val[1050]=9883;
val[1051]=9887;
val[1052]=9901;
val[1053]=9907;
val[1054]=9923;
val[1055]=9929;
val[1056]=9931;
val[1057]=9941;
val[1058]=9949;
val[1059]=9967;
val[1060]=9973;
size_nos=1061;
}

long long int search(long long int value)
{
    long long int i;
    for(i=0;i<size_nos;i++)if(value==val[i])return i;
}

long long int queue[1000000],vis[1111],start,end;

void init()
{
    for(i=0;i<1111;i++)
    {
        queue[i]=0;
        vis[i]=0;
    }
}

long long int enqueue(long long int s,long long int f)
{
    for(i=0;i<size[s];i++)
        {
            if(vis[a[s][i]]==0)
            {
                vis[a[s][i]]=vis[s]+1;
                if(a[s][i]==f)
                    return vis[f];
                push(a[s][i]);
                
            }
        }  
        return -1;

}
 
long long int bfs(long long int val,long long int val2)
{
    long long int ans,i,f=search(val2),s=search(val);
    start=end=0;
    if(val==val2)return 0;
    init();
    ans=enqueue(s,f);
    if(ans!=-1)return ans;
    while(start!=end)
    {
        s=pop();
        ans=enqueue(s,f);
        if(ans!=-1)return ans;
    }   
    return -1;
}

void insert(long long int v1,long long int v2)
{
    a[i][size[i]]=j;
    a[j][size[j]]=i;
    size[i]+=1;
    size[j]+=1;
}

int main()
{
    prime();
    for(i=0;i<1100;i++)size[i]=0;
    long long int t,i1,i2,af,cnt=0,it;
    for(i=0;i<size_nos;i++)
    {
        for(j=0;j<size_nos;j++)
        {
            cnt=0;
            i1=val[i];
            i2=val[j];
            for(it=0;it<4;it++)
            {
                if(i1%10==i2%10)cnt++;
                i1/=10;
                i2/=10;
            }
            if(cnt==3)
                insert(i,j);
        }
    }
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&i1,&i2);
        af=bfs(i1,i2);
        if(af!=-1)
        printf("%lld\n",af);
        else
        printf("Impossible\n");
    }
    return 0;
}
