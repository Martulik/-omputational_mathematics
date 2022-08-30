/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

/*MARKERS: //! = probably incorrect, //? = possibly incorrect*/

#include "FORSYTHE.H"

//     METO� P�H�E-K�TTA �E���EP�A �ETBEPTO�O-��TO�O �OP��KA

//     COCTAB�TE�� �PO�PAMM�-H.A.WATTS,L.F.SHAMPINE
//                SANDIA LABORATORIES
//              ALBUQUERQUE, NEW MEXICO

//     RKF45 �PE�HA�HA�EHA ��ABH�M O�PA�OM ��� PE�EH��
//     HE�ECTK�X � C�A�O �ECTK�X ����EPEH��A��H�X �PABHEH��,
//     KO��A B���C�EH�E �PO��BO�H�X HE C���KOM �OPO�OCTO��EE.
//     RKF45, BOO��E �OBOP�,HE C�E��ET �C�O���OBAT�
//     EC�� �O���OBATE�� TPE��ETC� B�COKA� TO�HOCT�

//     PE��ME

//     �O��PO�PAMMA RKF45 �HTE�P�P�ET C�CTEM� �� NEQN
//     O��KHOBEHH�X ����EPEH��A��H�X �PABHEH�� �EPBO�O
//     �OP��KA C�E����E�O B��A:

//            DY(I)/DT=F(T,Y(1),Y(2),...,Y(NEQN),

//     ��E Y(I) �A�AH� B T.
//     O���HO �O��PO�PAMM� �P�MEH��T ��� �HTE�P�POBAH��
//     OT T �O TOUT, O�HAKO EE MO�HO �C�O���OBAT� � KAK
//     O�HO�A�OB�� �HTE�PATOP,�TO�� �PO�O���T� PE�EH�E HA
//     O��H �A� B HA�PAB�EH�� TOUT.HA B�XO�E �APAMETPAM,
//     ����P�P����M B C��CKE B��OBA, �P�CBA�BA�TC� �HA�EH��,
//     HEO�XO��M�E ��� �PO�O��EH�� �HTE�P�POBAH��. �O���O-
//     BATE�� H��HO ���� E�E PA� O�PAT�T�C� K RKF45
//     (�,BO�MO�HO,O�PE�E��T� HOBOE �HA�EH�E ��� TOUT).
//     B �E�CTB�TE��HOCT� RKF45-�TO �PO�PAMMA �HTEP�E�CA,
//     KOTOPA� B���BAET �O��PO�PAMM� RKFS, OC��ECTB������
//     �PO�ECC PE�EH��.RKFS B CBO� O�EPE�� B���BAET �O��PO�-
//     PAMM� FEHL, KOTOPA� B���C��ET �P�����EHHOE PE�EH�E
//     HA O��H �A�.

//     RKF45 �C�O����ET METO� P�H�E-K�TTA-�E���EP�A, O��CAHH��
//     B C�E����E� �����KA���:E.FEHLBERG,LOW-ORDER CLASSICAL
//     RUNGE-KUTTA FORMULAS WITH STEPSIZE CONTROL,NASA TR R-315

//     CT��� PA�OT� �PO�PAMM� RKF45 ����CTP�P�ETC� B C�E�����X
//     �����KA���X:L.F.SHAMPINE,H.A.WATTS,S.DAVENPORT, SOLVING
//     NON-STIFF ORDINARY DIFFERENTIAL EQUATIONS-THE STAT OF
//     THE ART,SANDIA LABORATORIES REPORT SAND75-0182,SIAM
//     REVIEW,18(1976), N3,376-411.

//     �APAMETP� �PO�PAMM�:

//     F       -�O��PO�PAMMA F(T,Y,YP) ��� B���C�EH��
//              �PO��BO�H�X YP(I)=DY(I)/DT
//     NEQN    -��C�O �HTE�P�P�EM�X �PABHEH��
//     Y(*)    -PE�EH�E B TO�KE T
//     T       -HE�AB�C�MA� �EPEMEHHA�
//     TOUT    -TO�KA B�XO�A,B KOTOPO� H��HO O�PE�E��T�
//              �HA�EH�E PE�EH��
//     RELERR  -�PAH��A OTHOC�TE��HO� �O�PE�HOCT�
//              ��� TECTA �OKA��HO� O���K�.
//     ABSERR  -�PAH��A ABCO��THO� �O�PE�HOCT�
//              ��� TECTA �OKA��HO� O���K�.
//              HA KA��OM �A�E �PO�PAMMA TPE��ET B��O�HEH�� �C�OB��
//              ABS(LOCAL ERROR)<=RELERR*ABS(Y)+ABSERR
//              ��� KA��O� KOM�OHEHT� BEKTOPOB �OKA��HO�
//              O���K� � PE�EH��
//     IFLAG   -�KA�ATE�� PE��MA �HTE�P�POBAH��.
//     WORK(*) -MACC�B,CO�EP�A��� �H�OPMA���,BH�TPEHH�� ��� RKF45,
//              KOTOPA� HEO�XO��MA �P� �OC�E�����X B��OBAX.E�O
//              PA�MEPHOCT� �O��HA ��T� HE MEH��E 3+6*NEQN
//     IWORK(*)-�E��� MACC�B,CO�EP�A��� �H�OPMA���,BH�TPEHH�� ���
//              RKF45,KOTOPA� HEO�XO��MA �P� �OC�E�����X B��OBAX.
//              E�O PA�MEPHOCT� �O��HA ��T� HE MEH��E 5.

//     �EPBOE O�PA�EH�E K RKF45

//     �O���OBATE�� �O��EH �PE��CMOTPET� B CBOE� B���BA��E�
//     �PO�PAMME �AM�T� ��� C�E�����X MACC�BOB, ����P�P����X
//     B C��CKE B��OBA- Y(NEQN), WORK(3+6*NEQN), IWORK(5);
//     KPOME TO�O, OH �O��EH O�'�B�T� F B O�EPATOPE EXTERNAL,
//     �O��OTOB�T� �O��PO�PAMM� F(T,Y,YP) � �P�CBO�T� HA�A��-
//     H�E �HA�EH�� �APAMETPAM-

//     NEQN  -��C�O �HTE�P�P�EM�X �PABHEH�� (NEQN>=1)
//     Y(*)  -BEKTOP HA�A��H�X �C�OB��
//     T     -HA�A��HA� TO�KA �HTE�P�POBAH��,
//            T �O��HO ��T� �EPEMEHHO�.
//     TOUT  -TO�KA B�XO�A,B KOTOPO� H��HO HA�T� �HA�EH�E
//            PE�EH��. T=TOUT BO�MO�HO ���� �P� �EPBOM
//            O�PA�EH��.B �TOM C���AE B�XO� �� RKF45 �PO�-
//            CXO��T CO �HA�EH�EM �APAMETPA IFLAG=2,EC��
//            MO�HO �PO�O��AT� �HTE�P�POBAH�E.
//     RELERR-�PAH��A ��� OTHOC�TE��HO� �OKA��H�� �O�PE�HOCTE�.
//     ABSERR-�PAH��A ��� A�CO��THO�    �OKA��H�� �O�PE�HOCTE�.
//            �T� �PAH��� �O��H� ��T� HEOTP��ATE��H�.
//            RELERR �O��HA ��T� �EPEMEHHO�,A ABSERR MO�ET
//            ��T� � KOHCTAHTO�.�PO�PAMME, BOO��E �OBOP�
//            HE C�E��ET �A�ABAT� �PAH��� ��� OTHOC�TE��HO�
//            O���K�,MEH����, �EM �P�MEPHO 1.E-7. �A�� ���E�AT�
//            TP��HOCTE� ,CB��AHH�X C O�EH� B�COK�M� �A�POCAM�
//            K TO�HOCT�, �PO�PAMMA TPE��ET,�TO�� RELERR
//            ���A �O���E, �EM HEKOTOP�� �APAMETP OTHOC�TE��HO�
//            O���K�,B���C��EM�� BH�TP� EE � �AB�C���� OT
//            MA��H�.B �ACTHOCT�,HE PA�PE�AETC� �A�AH�E TO��KO
//            A�CO��THO� O���K�.EC�� �E �A�AHO �HA�EH�E RELERR,
//            MEH��EE �O��CT�MO�O, TO RKF45 �BE����BAET RELERR
//            HA��E�A��M O�PA�OM � BO�BPA�AET ��PAB�EH�E �O��-
//            �OBATE��, �PE��E �EM �PO�O��AT� �HTE�P�POBAH�E.
//     IFLAG-+1,-1.�TO �KA�ATE�� HACTPO�K� �PO�PAMM� ��� KA��O�
//            HOBO� �A�A��. HOPMA��HOE BXO�HOE �HA�EH�E PABHO+1.
//            �O���OBATE�� �O��EH �A�ABAT� IFLAG=-1 ���� B TOM
//            C���AE,  KO��A HEO�XO��MO ��PAB�EH�E O�HO�A�OB�M
//            �HTE�PATOPOM.B �TOM C���AE RKF45 ��TAETC� �PO�O���T�
//            PE�EH�E HA O��H �A� B HA�PAB�EH�� TOUT �P� KA��OM
//            O�EPE�HOM B��OBE. �OCKO��K� �TOT PE��M PA�OT�
//            BEC�MA HE�KOHOM��EH, E�O C�E��ET �P�MEH�T�
//            ���� B C���AE KPA�HE� HEO�XO��MOCT�.

//     �H�OPMA��� HA B�XO�E

//     Y(*)    -PE�EH�E B TO�KE T
//     T       -�OC�E�H�� TO�KA,�OCT��H�TA� �P� �HTE�P�POBAH��.
//     IFLAG=2 -�P��HTE�P�POBAH�� �OCT��H�TO TOUT.�TO �HA�EH�E
//              �APAMETPA �KA��BAET HA �C�E�H�� B�XO� �
//              �B��ETC� HOPMA��H�M PE��MOM ��� �PO�O��EH��
//              �HTE�P�POBAH��.
//          =3 -�HTE�P�POBAH�E HE ���O �AKOH�EHO ��-�A TO�O,
//              �TO �A�AHHOE �HA�EH�E �PAH��� ��� OTHOC�TE��HO�
//              O���K� OKA�A�OC� C���KOM MA�O. ��� �PO�O��EH��
//              �HTE�P�POBAH�� RELERR ���O HA��E�A��M O�PA�OM
//              �BE���EHO.
//          =4 -�HTE�P�POBAH�E HE ���O �AKOH�EHO ��-�A TO�O,
//              �TO �OTPE�OBA�OC� �O�EE 3000 B���C�EH�� �PO-
//              ��BO�HO�.�TO COOTBETCTBYET �P������TE��HO
//              500 �A�AM.
//          =5 -�HTE�P�POBAH�E HE ���O �AKOH�EHO ��-�A TO�O,
//              �TO PE�EH�E O�PAT��OC� B HY��,BC�E�CTB�E �E�O
//              TECT TO��KO OTHOC�TE��HO� O���K� HE �POXO��T.
//              ��� �PO�O��EH�� HEO�XO��MO HEHY�EBOE �HA�EH�E
//              �APAMETPA ABSERR. �C�O���OBAH�E HA O��H �A�
//              PE��MA �O�A�OBO�O �HTE�P�POBAH�� �B��ETC�
//              PA�YMH�M B�XO�OM �� �O�O�EH��.
//          =6 -�HTE�P�POBAH�E  HE ���O �AKOH�EHO ��-�A TO�O,
//              �TO TPE�YEMA� TO�HOCT� HE MO��A ��T� �OCT��H�TA
//              �A�E �P� HA�MEH��E� �O��CT� MO� BE����HE �A�A.
//              �O���OBATE�� �O��EH �BE����T� �PAH��� �O�PE�-
//              HOCT�,�PE��E �EM MO�HO ���ET �O��TAT�C�
//              �PO�O��AT� �HTE�P�POBAH�E.
//          =7 -�O BCE� B���MOCT�, RKF45 HE���EKT�BHA �P�
//              PE�EH�� �TO� �A�A��. C���KOM �O���OE ��C�O
//              TPE��EM�X B�XO�H�X TO�EK �PE��TCTB�ET B��OP�
//              ECTECTBEHHO� BE����H� �A�A.C�E��ET �C�O���OBAT�
//              PE��M �O�A�OBO�O �HTE�P�POBAH��.
//          =8 -HE�PAB���HOE �A�AH�E BXO�H�X �APAMETPOB.�TO
//              �HA�EH�E �O�B��ETC�,EC�� �O���EHA O�HA ��
//              C�E�����X O���OK-
//                              NEQN<=0
//                  T=TOUT  �  IFLAG!=+1  ��� -1
//                  RELERR  ���  ABSERR<0
//                  IFLAG==0  ��� <-2  ��� >8
//     WORK(*) -�H�OPMA���, KOTOPA� O���HO HE �PE�CTAB��ET �HTE-
//              PECA ��� �O���OBATE��, HO HEO�XO��MA �P� �OC�E-
//              �����X B��OBAX. WORK(1),...,WORK(NEQN) CO�EP�AT
//              �EPB�E �PO��BO�H�E BEKTOPA PE�EH�� Y B TO�KE T.
//              WORK(NEQN+1) XPAH�T BE����H� �A�A H,C KOTOPO�
//              MO�HO �O��TAT�C� �POBECT� C�E������ �A�.
//     IWORK(*) -�H�OPMA���, KOTOPA� O���HO HE �PE�CTAB��ET �HTE-
//               PECA ��� �O���OBATE��, HO HEO�XO��MA �P� �OC�E-
//               �����X B��OBAX. B IWORK(1) CO�EP��TC�
//               C�ET��K ��C�A B���C�EH�� �PO��BO�H�X.

//     �OC�E�����E O�PA�EH�� K RKF45

//          HA B�XO�E �O��PO�PAMM� RKF45 �MEETC� BC� �H�OPMA���,
//     HEO�XO��MA�  ��� �PO�O��EH�� �HTE�P�POBAH��.EC�� �P�
//     �HTE�P�POBAH�� �OCT��H�TO TOUT,TO �O���OBATE�� �OCTA-
//     TO�HO O�PE�E��T� HOBOE �HA�EH�E  TOUT � CHOBA O�PAT�T�-
//     C� K RKF45.
//          B PE��ME �O�A�OBO�O �HTE�P�POBAH�� (IFLAG=-2)
//     �O���OBATE�� �O��EH �MET� B B���,�TO KA���� �A�
//     B��O�H�ETC� B HA�PAB�EH�� TEK��E�O �HA�EH�� TOUT
//     (C��HA����P�EMOM  ��MEHEH�EM IFLAG HA 2). �O���OBATE��
//     �O��EH �A�AT� HOBOE �HA�EH�E TOUT � �EPEO�PE�E��T�
//     IFLAG HA -2, �TO�� �PO�O��AT� B PE��ME �O�A�OBO�O
//     �HTE�P�POBAH��.
//          EC�� �HTE�P�POBAH�E HE ���O �AKOH�EHO,HO
//     �O���OBATE�� XO�ET �PO�O��AT� (C���A� IFLAG=3,4), OH
//     �O�POCT� CHOBA O�PA�AETC� K RKF45.�P� IFLAG=3 �APA-
//     METP RELERR ���  ��MEHEH HA��E�A��M ��� �PO�O��EH��
//     �HTE�P�POBAH�� O�PA�OM.B C���AE IFLAG=4 C�ET��K
//     ��C�A �HA�EH�� ��HK��� ���ET �EPEO�PE�E�EH HA 0, �
//     ����T PA�PE�EH� E�E 3000 B���C�EH�� ��HK���.
//          O�HAKO B C���AE IFLAG=5, �PE��E �EM MO�HO ���ET
//     �PO�O��AT� �HTE�P�POBAH�E,�O���OBATE�� �O��EH CHA�A�A
//     ��MEH�T� KP�TEP�� O���K�, �A�AB �O�O��TE��HOE �HA�EH�E
//     ��� ABSERR. EC�� OH HE C�E�AET �TO�O, B��O�HEH�E �PO-
//     �PAMM� ���ET �PEKPA�EHO.
//        TO�HO TAK �E,B C���AE IFLAG=6,�PE��E �EM �PO�O�-
//     �AT� �HTE�P�POBAH�E,�O���OBATE�� HEO�XO��MO �EPEO�PE-
//     �E��T� IFLAG HA 2 (��� -2, EC�� �C�O����ETC� PE��M
//     �O�A�OBO�O �HTE�P�POBAH��) � �BE����T� �HA�EH�E ���
//     ABSERR ���O RELERR,���O � ��� TO�O,� ��� �P��O�O.
//     EC�� �TO HE ���ET C�E�AHO,B��O�HEH�E �PO�PAMM�
//     �PEKPA�AETC�. �O�B�EH�E IFLAG=6 �KA��BAET HA HEPE��-
//     ��PHOCT� (PE�EH�E ��CTPO MEH�ETC� ���, BO�MO�HO,
//     �MEETC� OCO�EHHOCT�),� �ACTO B �O�O�H�X C���A�X
//     HE �MEET CM�C�A �PO�O��AT� �HTE�P�POBAH�E.
//          EC�� ���ET �O���EHO �HA�EH�E IFLAG=7,TO �O���O-
//     BATE�� �O��EH �EPE�T� K PE��M� �O�A�OBO�O �HTE�P�PO-
//     BAH�� C BE����HO� �A�A,O�PE�E��EMO� �PO�PAMMO�, ���
//     PACCMOTPET� BO�MO�HOCTT� �EPEXO�A HA �PO�PAMM� METO�OB
//     A�AMCA.EC�� BCE �E �O���OBATE�� XO�ET �PO�O��AT�
//     �HTE�P�POBAH�E �O �O��PO�PAMME RKF45,OH �O��EH �O HOBO�O
//     O�PA�EH�� K HE� �EPEO�PE�E��T� IFLAG HA 2.B �POT�BHOM
//     C���AE B��O�HEH�E �PO�PAMM� ���ET �PEKPA�EHO.
//          EC�� �O���EHO �HA�EH�E IFLAG=8,TO �HTE�P�POBAH�E
//     HE���� �PO�O��AT�,�OKA HE ����T �C�PAB�EH� O���O�H�E
//     BXO�H�E �APAMETP�. H��HO OTMET�T�,�TO MACC�B� WORK �
//     IWORK CO�EP�AT �H�OPMA���,HEO�XO��M�� ��� �A��HE��E�O
//     �HTE�P�POBAH��.�O�TOM� B �T� MACC�B� HE���� BHOC�T�
//     ��MEHEH��.

void FEHL(void(F)(REAL T,REAL*Y,REAL*YP),int NEQN,REAL *Y,REAL &T,REAL H,REAL *YP,REAL *F1,REAL *F2,REAL *F3,REAL *F4,REAL *F5,REAL *S)
{

//     METO� P�H�E-K�TTA-�E���EP�A �ETBEPTO�O-��TO�O �OP��KA

//     �O��PO�PAMMA FEHL �HTE�P�P�ET C�CTEM� �� NEQN
//     O��KHOBEHH�X ����EPEH��A��H�X �PABHEH�� �EPBO�O
//     �OP��KA C�E����E�O B��A

//          DY(I)/DT=F(T,Y(1),...Y(NEQN)),

//     ��E HA�A��H�E �HA�EH�� Y(I) � HA�A��H�E �PO��BO�H�E
//     YP(I) �A�AH� B HA�A��HO� TO�KE T. FEHL �PO�O��AET
//     PE�EH�E HA ��KC�POBAHH�� �A� H � �OME�AET B MACC�B
//     S(I) �P�����EH�E K PE�EH�� B TO�KE T+H, �ME��EE ��T��
//     �OP��OK TO�HOCT� (�OKA��H�� �OP��OK PABEH �ECT�).
//     F1,...F5-MACC�B� PA�MEPHOCT� NEQN,HEO�XO��M�E BH�TP�
//     �PO�PAMM�.
//          B �OPM��AX �PO��BE�EHA �P����POBKA C �E���
//     �MEH���T� �OTEP� BEPH�X �HAKOB.
//          �TO�� MO�HO ���O PA����AT� PA�H�E HE�AB�C�M�E
//     AP��MEHT�, �P� O�PA�EH�� K FEHL HE C�E��ET �A�ABAT�
//     ��� H �HA�EH�E,MEH��EE �MHO�EHHHO� HA 13 O���K�
//     OKP���EH�� B T.


REAL CH;
int K;

CH=H/4.0;
for( K=1; K<=NEQN; K++)F5[K-1]=Y[K-1]+CH*YP[K-1];

F(T+CH,F5,F1);
CH=3.0*H/32.0;
for( K=1; K<=NEQN; K++)F5[K-1]=Y[K-1]+CH*(YP[K-1]+3.0*F1[K-1]);
F(T+3.0*H/8.0,F5,F2);

CH=H/2197.0;
for( K=1; K<=NEQN; K++)F5[K-1]=Y[K-1]+CH*(1932.0*YP[K-1]+(7296.0*F2[K-1]-7200.0*F1[K-1]));
F(T+12.0*H/13.0,F5,F3);

CH=H/4104.0;
for( K=1; K<=NEQN; K++)F5[K-1]=Y[K-1]+CH*((8341.0*YP[K-1]-845.0*F3[K-1])+(29440.0*F2[K-1]-32832.0*F1[K-1]));
F(T+H,F5,F4);

CH=H/20520.0;
for( K=1; K<=NEQN; K++)F1[K-1]=Y[K-1]+CH*((-6080.0*YP[K-1]+(9295.0*F3[K-1]-5643.0*F4[K-1]))+(41040.0*F1[K-1]-28352.0*F2[K-1]));
F(T+H/2.0,F1,F5);

//     B���C��T� �P�����EHHOE PE�EH�E B TO�KE T+H

CH=H/7618050.0;
for( K=1; K<=NEQN; K++)S[K-1]=Y[K-1]+CH*((902880.0*YP[K-1]+(3855735.0*F3[K-1]-1371249.0*F4[K-1]))+(3953664.0*F2[K-1]+277020.0*F5[K-1]));

return; 
}                         	// END


void RKFS(void(F)(REAL T,REAL*Y,REAL*YP),int NEQN,REAL *Y,REAL &T,REAL TOUT,REAL &RELERR,REAL &ABSERR,int &IFLAG,REAL *YP,REAL H,REAL *F1,REAL *F2,REAL *F3,REAL *F4,REAL *F5,REAL SAVRE,REAL SAVAE)
{

//     METO� P�H�E-K�TTA-�E���EP�A �ETBEPTO�O-��TO�O �OP��KA
//     RKFS �HTE�P�P�ET C�CTEM� O��KHOBEHH�X ����E-
//     PEH��A��H�X �PABHEH�� �EPBO�O �OP��KA(CM. KOM-
//     MEHTAP�� K RKF45). MACC�B� YP,F1,F2,F3,F4 � F5
//     (PA�MEPHOCT� �O KPA�HE� MEPE NEQN) � �EPEMEH-
//     H�E H,SAVRE,SAVAE,NFE,KOP,INIT,JFLAG � KFLAG
//     �C�O�����TC� BH�TP� �PO�PAMM� � B�HECEH� B
//     C��COK B��OBA,�TO�� COXPAH�T� �X O�PE�E�EH-
//     HOCT� �P� �OBTOPHOM O�PA�EH��.�O�TOM� �X �HA-
//     �EH�� HE �O��H�  ��MEH�T�C�  �O���OBATE�EM.
//     BO�MO�H�� �HTEPEC �PE�CTAB���T �APAMETP�
//     YP  -�PO��BO�HA� BEKTOPA PE�EH�� B TO�KE T
//     H   -�PE��O�A�AEM�� PA�MEP �A�A ��� O�EPE�HO�O �TA�A
//     NFE -C�ET��K ��C�A B���C�EH�� ��HK���

bool HFAILD,OUTPUT;
static int NFE,KOP,INIT,JFLAG,KFLAG;
REAL A,AE,DT,EE,EEOET,ESTTOL,ET,HMIN,RER,S,SCALE,TOL,TOLN,U26,EPSP1,EPS,YPK;
int K,MFLAG;


//     REMIN-�TO M�H�MA��HOE �O��CT�MOE �HA�EH�E ���
//     RELERR.�O��TK� �O����T� �O �TO� �O��PO�PAMME
//     �O�EE B�COK�� TO�HOCT� O���HO CTO�T O�EH�
//     �OPO�O � �A�ACT�� �E��C�E�H�.

REAL REMIN= 1.E-12;

//     CTO�MOCT� C�ETA KOHTPO��P�ETC� TPE�OBAH�EM,
//     �TO�� KO���ECTBO B���C�EH�� ��HK��� ���O O�-
//     PAH��EHO BE����HO�,�P������TE��HO PABHO� �HA-
//     �EH�� �APAMETPA MAXNFE.�P�H�TOE ��EC� �HA�E-
//     H�E �P�MEPHO COOTBETCTB�ET 500 �A�AM.

int MAXNFE= 3000;

//     �POBEP�T� BXO�H�E �APAMETP�

if(NEQN<1)goto _10;
if((RELERR<0.0)||(ABSERR<0.0))goto _10;
MFLAG=ABS(IFLAG);
if((MFLAG==0)||(MFLAG>8))goto _10;
if(MFLAG!=1)goto _20;

//     �EPB�� B��OB,B���C��T� MA��HHOE ��C��OH

EPS=1.0;
_5:;
EPS=EPS/2.0;
EPSP1=EPS+1.;
if(EPSP1>1.)goto _5;
U26=26.*EPS;
goto _50;

//     O���KA BXO�HO� �H�OPMA���

_10:;
IFLAG=8;
return;  //?

//     �POBEP�T� BO�MO�HOCT� �PO�O��EH��

_20:;
if((T==TOUT)&&(KFLAG!=3))goto _10;
if(MFLAG!=2)goto _25;

//     IFLAG=+2 ��� -2

if((KFLAG==3)||(INIT==0))goto _45;
if(KFLAG==4)goto _40;
if((KFLAG==5)&&(ABSERR==0.0))goto _30;
if((KFLAG==6)&&(RELERR<=SAVRE)&&(ABSERR<=SAVAE))goto _30;
goto _50;

//     IFLAG=3,4,5,6,7 ��� 8

_25:;
if(IFLAG==3)goto _45;
if(IFLAG==4)goto _40;
if((IFLAG==5)&&(ABSERR>0.0))goto _45;

//     �HTE�P�POBAH�E HE���� �PO�O��AT�,�OCKO��K� �O��-
//     �OBATE�� HE B��O�H�� �HCTP�K���,COOTBETCTB����X
//     �HA�EH��M IFLAG=5,6,7 ��� 8

_30:;
//printf("�HTE�P�POBAH�E �PEPBAHO, �OCKO��K� �O���OBATE��"
//"HE B��O�H�� �HCTP�K��� RKF45, COOTBETCTB����X"
//"�HA�EH��M IFLAG=5,6,7 ��� 8");
exit(0); 

//     �EPEO�PE�E��T� C�ET��K ��C�A B���C�EH�� ��HK���

_40:;
NFE=0;
if(MFLAG==2)goto _50;

//     �EPEO�PE�E��T� �HA�EH�E FLAG,�CTAHOB�EHHOE
//     �P� �PE�����EM O�PA�EH��

_45:;
IFLAG=JFLAG;
if(KFLAG==3)MFLAG=ABS(IFLAG);

//     COXPAH�T� BXO�HOE �HA�EH�E IFLAG � �CTAHOB�T�
//     �HA�EH�E FLAG, COOTBETCTB���EE �PO�O��EH��,
//     ��� �����E� �POBEPK�

_50:;
JFLAG=IFLAG;
KFLAG=0;

//     COXPAH�T� �HA�EH�� RELERR � ABSERR ��� BXO�HO�
//     �POBEPK� �P� �OC�E�����X O�PA�EH��X

SAVRE=RELERR;
SAVAE=ABSERR;

//     �CTAHOB�T� �HA�EH�E �PAH��� ��� OTHOC�TE��-
//     HO� �O�PE�HOCT�,PABHOE KAK M�H�M�M 2*EPS+
//     REMIN,�TO�� ���E�AT� TP��HOCTE�,CB��AHH�X
//     C TPE�OBAH�EM HE�OCT���MO� TO�HOCT�

RER=2.*EPS+REMIN;
if(RELERR>=RER)goto _55;

//     �A�AHHA� �PAH��A OTHOC�TE��HO� �O�PE�HOCT�
//     C���KOM MA�A

RELERR=RER;
IFLAG=3;
KFLAG=3;
return;  //?

_55:;
DT=TOUT-T;

if(MFLAG==1)goto _60;
if(INIT==0)goto _65;
goto _80;

//     �P�CBOEH�E HA�A��H�X �HA�EH�� (�H����POBA-
//             H�E)-�CTAHOB�T� �HA�EH�E �KA�ATE��
//             OKOH�AH�� �H����POBAH��,INIT
//             �CTAHOB�T� �HA�EH�E �KA�ATE�� C���-
//             KOM �O���O�O �ATPE�OBAHHO�O ��C�A B�-
//             XO�H�X TO�EK,KOP
//             B���C��T� HA�A��H�E �PO��BO�H�E
//             �CTAHOB�T� �HA�EH�E C�ET��KA ��C�A
//             B���C�EH�� ��HK���,NFE
//             O�EH�T� HA�E��H�� BE����H� �A�A

_60:;
INIT=0;
KOP=0;

A=T;
F(A,Y,YP);
NFE=1;
if(T!=TOUT)goto _65;
IFLAG=2;
return;  //?

_65:;
INIT=1;
H=ABS(DT);
TOLN=0.;
for( K=1; K<=NEQN; K++){   //? target=70
TOL=RELERR*ABS(Y[K-1])+ABSERR;
if(TOL<=0)goto _70;
TOLN=TOL;
YPK=ABS(YP[K-1]);
if(YPK*pow(H,5)>TOL)H=pow((TOL/YPK),0.2);
_70:;
}                         	// CONTINUE
if(TOLN<=0.0)H=0.0;
H=MAX(H,U26*MAX(ABS(T),ABS(DT)));
JFLAG=SIGN(2,IFLAG);

//     �P�CBO�T� BE����HE �A�A �HAK,COOTBETCTB�����
//     �HTE�P�POBAH�� B HA�PAB�EH�� OT T K TOUT

_80:;
H=SIGN(H,DT);

//     �POBEPKA, HACKO��KO CEP�E�HO B���H�E HA RKF45
//     C���KOM �O���O�O �ATPE�OBAHHO�O ��C�A B�XO�-
//     H�X TO�EK

if(ABS(H)>=2.0*ABS(DT))KOP=KOP+1;
if(KOP!=100)goto _85;

//     �PE�MEPHA� �ACTOTA B�XO�OB

KOP=0;
IFLAG=7;
return;

_85:;
if(ABS(DT)>U26*ABS(T))goto _95;

//     EC�� O�EH� ����KO K TO�KE B�XO�A,�PO�KCTPA�O-
//     ��POBAT� � BEPH�T�C� �O MECT� B��OBA

for( K=1; K<=NEQN; K++)Y[K-1]=Y[K-1]+DT*YP[K-1];
A=TOUT;
F(A,Y,YP);
NFE=NFE+1;
goto _300;

//     �P�CBO�T� HA�A��HOE �HA�EH�E �H��KATOP� TO�K�
//     B�XO�A

_95:;
OUTPUT=false;

//     �TO�� ���E�AT� HEO�PAB�AHHO�O MA��HHO�O H���
//     �P� B���C�EH�� ��HK��� OT �PAH�� �O�PE�HO-
//     CTE�,�POMAC�TA��POBAT� �T� �PAH���

SCALE=2./RELERR;
AE=SCALE*ABSERR;

//     �O�A�OBOE �HTE�P�POBAH�E

_100:;
HFAILD=false;

//     �CTAHOB�T� HA�MEH���� �O��CT�M�� BE����H� �A�A

HMIN=U26*ABS(T);

//     �C�PAB�T� �P� HEO�XO��MOCT� BE����H� �A�A,
//     �TO�� �OCT��H�T� TO�K� B�XO�A. PACC��TAT� HA
//     �BA �A�A B�EPE�,�TO�� ���E�AT� C���KOM PE�K�X
//     ��MEHEH�� B BE����HE �A�A � TEM CAM�M �MEH�-
//     ��T� B���H�E B�XO�H�X TO�EK HA �PO�PAMM�.

DT=TOUT-T;
if(ABS(DT)>=2.*ABS(H))goto _200;
if(ABS(DT)>ABS(H))goto _150;

//     C�E������ �C�E�H�� �A� �ABEP��T �HTE�P�PO-
//     BAH�E �O �KA�AHHO� TO�K� B�XO�A

OUTPUT=true;
H=DT;
goto _200;

_150:;
H=0.5*DT;



//     BH�TPEHH�� O�HO�A�OB�� �HTE�PATOP

//     �PAH��� �O�PE�HOCTE� ���� �POMAC�TA��POBAH�,
//     �TO�� ���E�AT� HEO�PAB�AHHO�O MA��HHO�O H���
//     �P� B���C�EH�� ��HK��� OT H�X.
//     �TO�� ���E�AT� O�PA�EH�� B H��� �HAMEHATE��
//     B TECTE,OTHOC�TE��HA� O���KA ��MEP�ETC�  �O
//     OTHO�EH�� K CPE�HEM�  �� BE����H PE�EH��
//     B HA�A�E � KOH�E �A�A.
//     B �OPM��E,O�EH�BA��E� O���K�,�PO��BE�EHA
//     �P����POBKA C�A�AEM�X,�MEH��A��A� �OTEP�
//     BEPH�X �HAKOB.
//     �TO�� PA����AT� ME��� CO�O� PA�H�E AP��MEHT�,
//     ��� H HE �O��CKA�TC� �HA�EH��,MEH���E �MHO-
//     �EHHO� HA 26 O���K� OKP���EH�� B T.
//     BBE�EH� �PAKT��ECK�E O�PAH��EH�� HA CKOPOCT�
//     ��MEHEH�� BE����H� �A�A,�TO�� C��A��T� �PO-
//     �ECC B��OPA �TO� BE����H� � ���E�AT� �PE�MEP-
//     HO�O EE PA��POCA B �A�A�AX C HAP��EH�EM HE�PE-
//     P�BHOCT�.
//     �� �PE�OCTOPO�HOCT� �PO�PAMMA �EPET 9/10 OT TO�
//     BE����H� �A�A,KOTOPA� H��HA �O EE O�EHKE.
//     EC��HA �AHHOM �A�E ���A HE��A�HA� �O��TKA
//     TO �P� ��AH�POBAH�� C�E����E�O �BE���EH�E
//     ���H� �A�A HE �O��CKAETC�. �TO �OB��AET ���EK-
//     T�BHOCT� �PO�PAMM� ��� �A�A� C PA�P�BAM� �
//     B O��EM C���AE,�OCKO��K� �C�O����ETC� �OKA��-
//     HA� �KCTPA�O����� � �O�O�H�TE��HA� �PE�OCTO-
//     PO�HOCT� KA�ETC� O�PAB�AHHO�.


//     �POBEP�T� ��C�O B���C�EH�� �PO��BO�H�X.EC��
//     OHO HE �PEB��AET �CTAHOB�EHHO�O �PE�E�A,�O-
//     �PO�OBAT� �PO�O���T� �HTE�P�POBAH�E C T �O T+H

_200:;
if(NFE<=MAXNFE)goto _220;

//     C���KOM �O���A� PA�OTA

IFLAG=4;
KFLAG=4;
return;

//     �PO�O���T� �P�����EHHOE PE�EH�E HA O��H �A� ���H� H

_220:;
FEHL(F,NEQN,Y,T,H,YP,F1,F2,F3,F4,F5,F1);
NFE=NFE+5;

//     B���C��T� � CPABH�T� �O��CT�M�E �PAH��� �
//     O�EHK� �OKA��HO� O���,A �ATEM CH�T� MAC�TA-
//     ��POBAH�E �PAH��.�AMET�TE,�TO OTHOC�TE��HA�
//     O���KA ��MEP�ETC� �O OTHO�EH�� K CPE�HEM� ��
//     BE����H PE�EH�� B HA�A�E � KOH�E �A�A.

EEOET=0.;
for( K=1; K<=NEQN; K++){   //? target=250
ET=ABS(Y[K-1])+ABS(F1[K-1])+AE;
if(ET>0.)goto _240;

//     HE�PAB���HA� �PAH��A �O�PE�HOCT�

IFLAG=5;
KFLAG=5;
return;

_240:;
EE=ABS((-2090.*YP[K-1]+(21970.*F3[K-1]-15048.*F4[K-1]))+(22528.*F2[K-1]-27360.*F5[K-1]));
//_250:;
EEOET=MAX(EEOET,EE/ET);
}

ESTTOL=ABS(H)*EEOET*SCALE/752400.;

if(ESTTOL<=1.0)goto _260;


//     HE��A�H�� �A�
//            �MEH���T� BE����H� �A�A � CHOBA �O-
//            �PO�OBAT�
//            �MEH��EH�E O�PAH���BAETC� CH��� MHO-
//            ��TE�EM 1/10

HFAILD=true;
OUTPUT=false;
S=0.1;
if(ESTTOL<59049.)S=0.9/pow(ESTTOL,0.2);
H=S*H;
if(ABS(H)>HMIN)goto _200;

//     �A�AHHA� �PAH��A O���K� HE�OCT���MA �A�E �P�
//     HA�MEH��E� �O��CT�MO� BE����HE �A�A

IFLAG=6;
KFLAG=6;
return;  //?


//     �C�E�H�� �A�
//            �OMECT�T� B MACC�B Y PE�EH�E B TO�KE
//            T+H � B���C��T� �PO��BO�H�E B �TO�
//            TO�KE

_260:;
T=T+H;
for( K=1; K<=NEQN; K++)Y[K-1]=F1[K-1];
A=T;
F(A,Y,YP);
NFE=NFE+1;


//     B��PAT� BE����H� C�E����E�O �A�A
//     �BE���EH�E O�PAH��EHO MHO��TE�EM 5
//     EC�� HA �AHHOM �A�E ���A HE��A�HA�
//     �O��TKA,TO ��� C�E����E�O HE �O��-
//     CKAETC� B��OP �O���E� BE����H� �A�A

S=5.;
if(ESTTOL>1.889568E-4)S=0.9/pow(ESTTOL,0.2);
if(HFAILD)S=MIN(S,1.0);
H=SIGN(MAX(S*ABS(H),HMIN),H);

//     KOHE� O�HO�A�OBO�O �HTE�PATOPA


//     H��HO �� �E�AT� O�EPE�HO� �A�

if(OUTPUT)goto _300;
if(IFLAG>0)goto _100;


//     �HTE�P�POBAH�E �C�E�HO �ABEP�EHO

//     PE��M O�HO�A�OBO�O �HTE�P�POBAH��

IFLAG=-2;
return;

//     PE��M �HTE�P�POBAH�� HA �HTEPBA�E

_300:;
T=TOUT;
IFLAG=2;
return;

}                         	// END

void RKF45(void(F)(REAL T,REAL*Y,REAL*YP),int NEQN,REAL *Y,REAL &T,REAL TOUT,REAL &RELERR,REAL &ABSERR,REAL *WORK,int &IFLAG)
{
//     EC�� TPAHC��TOP �POBEP�ET �H�EKC�, TO �AMEH�T�
//     WORK[0] HA WORK[2+6*NEQN]

int K1,K2,K3,K4,K5,K6,K1M;

//     B���C��T� �H�EKC� ��� PAC�E��EH�� PA�O�E�O MACC�BA

K1M=NEQN;
K1=K1M+1;
K2=K1+NEQN;
K3=K2+NEQN;
K4=K3+NEQN;
K5=K4+NEQN;
K6=K5+NEQN;

//     �TA �POME�YTO�HA� �PO�PAMMA �POCTO COKPA�AET ���
//     �O���OBATE�� ���HH�� C��COK B��OBA �YTEM PAC�E��EH��
//     �BYX PA�O��X MACC�BOB. EC�� �TO HE COBMECT�MO C
//     TPAHC��TOPOM,TO OH �O��EH O�PA�AT�C� HE�OCPE�CTBEHHO
//     K �O��PO�PAMME RKFS .

RKFS(F,NEQN,Y,T,TOUT,RELERR,ABSERR,IFLAG,WORK,WORK[K1M],&WORK[K1],&WORK[K2],&WORK[K3],&WORK[K4],&WORK[K5],WORK[K6],WORK[K6+1]);
return;  
}                         	// END


