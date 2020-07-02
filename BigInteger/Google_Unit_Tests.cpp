#include "pch.h"
#include "..\acmp\BigInteger\BigInteger.cpp"


TEST(correctness, handAdd) {
	BigInteger a = BigInteger::valueOf("0");
	BigInteger b = BigInteger::valueOf("1");
	BigInteger c = BigInteger::valueOf("10");
	BigInteger d = BigInteger::valueOf("11");
	BigInteger e = BigInteger::valueOf("99");
	BigInteger f = BigInteger::valueOf("1000");
	BigInteger g = BigInteger::valueOf("100000000");

	BigInteger aa = BigInteger::valueOf("0");
	BigInteger ab = BigInteger::valueOf("1");
	BigInteger bc = BigInteger::valueOf("11");
	BigInteger ac = BigInteger::valueOf("10");
	BigInteger be = BigInteger::valueOf("100");
	BigInteger de = BigInteger::valueOf("110");
	BigInteger ce = BigInteger::valueOf("109");
	BigInteger gfcb = BigInteger::valueOf("100001011");

	EXPECT_EQ(a + a, aa);
	EXPECT_EQ(a + b, ab);
	EXPECT_EQ(b + c, bc);
	EXPECT_EQ(a + c, ac);
	EXPECT_EQ(b + e, be);
	EXPECT_EQ(d + e, de);
	EXPECT_EQ(c + e, ce);
	EXPECT_EQ(g + f + c + b, gfcb);
}

TEST(correctness, handSub) {
	BigInteger a = BigInteger::valueOf("0");
	BigInteger b = BigInteger::valueOf("1");
	BigInteger c = BigInteger::valueOf("10");
	BigInteger d = BigInteger::valueOf("11");
	BigInteger e = BigInteger::valueOf("99");
	BigInteger f = BigInteger::valueOf("1000");
	BigInteger g = BigInteger::valueOf("100000000");

	BigInteger aa = BigInteger::valueOf("0");
	BigInteger ab = BigInteger::valueOf("-1");
	BigInteger bc = BigInteger::valueOf("-9");
	BigInteger cb = BigInteger::valueOf("9");
	BigInteger ac = BigInteger::valueOf("-10");
	BigInteger BEe = BigInteger::valueOf("99");
	BigInteger de = BigInteger::valueOf("-88");
	BigInteger fe = BigInteger::valueOf("901");
	BigInteger ga = g;
	BigInteger gb = BigInteger::valueOf("99999999");
	BigInteger gf = BigInteger::valueOf("99999000");



	EXPECT_EQ(a - a, aa);
	EXPECT_EQ(a - b, ab);
	EXPECT_EQ(b - c, bc);
	EXPECT_EQ(c - b, cb);
	EXPECT_EQ(a - c, ac);
	EXPECT_EQ((b + e) - b, BEe);
	EXPECT_EQ(d - e, de);
	EXPECT_EQ(f - e, fe);
	EXPECT_EQ(g - a, ga);
	EXPECT_EQ(g - b, gb);
	EXPECT_EQ(g - f, gf);

}

TEST(correctness, handMult) {
	BigInteger a = BigInteger::valueOf("0");
	BigInteger b = BigInteger::valueOf("1");
	BigInteger c = BigInteger::valueOf("10");
	BigInteger d = BigInteger::valueOf("11");
	BigInteger e = BigInteger::valueOf("99");
	BigInteger f = BigInteger::valueOf("1000");
	BigInteger g = BigInteger::valueOf("100000000");

	BigInteger aa = BigInteger::valueOf("0");
	BigInteger bc = BigInteger::valueOf("10");
	BigInteger cd = BigInteger::valueOf("110");
	BigInteger ce = BigInteger::valueOf("990");
	BigInteger fg = BigInteger::valueOf("100000000000");

	EXPECT_EQ(a * a, aa);
	EXPECT_EQ(a * b, aa);
	EXPECT_EQ(a * g, aa);
	EXPECT_EQ(b * c, bc);
	EXPECT_EQ(c * b, bc);
	EXPECT_EQ(c * d, cd);
	EXPECT_EQ(d * c, cd);
	EXPECT_EQ(c * e, ce);
	EXPECT_EQ(e * c, ce);
	EXPECT_EQ(f * g, fg);
	EXPECT_EQ(g * f, fg);
}

TEST(correctness, handDiv) {
	BigInteger a = BigInteger::valueOf("0");
	BigInteger b = BigInteger::valueOf("1");
	BigInteger c = BigInteger::valueOf("10");
	BigInteger d = BigInteger::valueOf("11");
	BigInteger e = BigInteger::valueOf("99");
	BigInteger f = BigInteger::valueOf("1000");
	BigInteger g = BigInteger::valueOf("100000000");

	BigInteger ab = BigInteger::valueOf("0");
	BigInteger bc = BigInteger::valueOf("0");
	BigInteger cb = BigInteger::valueOf("10");
	BigInteger ed = BigInteger::valueOf("9");
	BigInteger eb = BigInteger::valueOf("99");
	BigInteger gf = BigInteger::valueOf("100000");

	EXPECT_EQ(a / b, ab);
	EXPECT_EQ(b / c, bc);
	EXPECT_EQ(c / b, cb);
	EXPECT_EQ(e / d, ed);
	EXPECT_EQ(e / b, eb);
	EXPECT_EQ(g / f, gf);
}

TEST(correctness, handDivMod) {
	BigInteger a = BigInteger::valueOf("1");
	BigInteger b = BigInteger::valueOf("2");
	BigInteger c = BigInteger::valueOf("5");
	BigInteger d = BigInteger::valueOf("7");
	BigInteger e = BigInteger::valueOf("10");
	BigInteger f = BigInteger::valueOf("13");
	BigInteger g = BigInteger::valueOf("15");

	BigInteger ab = BigInteger::valueOf("1");
	BigInteger ba = BigInteger::valueOf("0");
	BigInteger cd = BigInteger::valueOf("5");
	BigInteger cb = BigInteger::valueOf("1");
	BigInteger gf = BigInteger::valueOf("2");
	BigInteger gd = BigInteger::valueOf("1");
	BigInteger gc = BigInteger::valueOf("0");
	BigInteger ed = BigInteger::valueOf("3");
	BigInteger ec = BigInteger::valueOf("0");

	EXPECT_EQ(a % b, ab);
	EXPECT_EQ(b % a, ba);
	EXPECT_EQ(c % d, cd);
	EXPECT_EQ(c % b, cb);
	EXPECT_EQ(g % f, gf);
	EXPECT_EQ(g % d, gd);
	EXPECT_EQ(g % c, gc);
	EXPECT_EQ(e % d, ed);
	EXPECT_EQ(e % c, ec);
}

TEST(correctness, handPow) {
	BigInteger a = BigInteger::valueOf("0");
	BigInteger b = BigInteger::valueOf("1");
	BigInteger c = BigInteger::valueOf("-2");
	BigInteger d = BigInteger::valueOf("3");

	long long e = 0;
	long long f = 1;
	long long g = 2;
	long long h = 3;
	long long i = 5;

	BigInteger ae = BigInteger::valueOf("1");
	BigInteger af = BigInteger::valueOf("0");
	BigInteger de = BigInteger::valueOf("1");
	BigInteger bi = BigInteger::valueOf("1");
	BigInteger ce = BigInteger::valueOf("1");
	BigInteger cf = BigInteger::valueOf("-2");
	BigInteger cg = BigInteger::valueOf("4");
	BigInteger ci = BigInteger::valueOf("-32");
	BigInteger df = BigInteger::valueOf("3");
	BigInteger dg = BigInteger::valueOf("9");
	BigInteger dh = BigInteger::valueOf("27");
	BigInteger di = BigInteger::valueOf("243");

	EXPECT_EQ(BigInteger::pow(a, e), ae);
	EXPECT_EQ(BigInteger::pow(a, f), af);
	EXPECT_EQ(BigInteger::pow(d, e), de);
	EXPECT_EQ(BigInteger::pow(b, i), bi);
	EXPECT_EQ(BigInteger::pow(c, e), ce);
	EXPECT_EQ(BigInteger::pow(c, f), cf);
	EXPECT_EQ(BigInteger::pow(c, g), cg);
	EXPECT_EQ(BigInteger::pow(c, i), ci);
	EXPECT_EQ(BigInteger::pow(d, f), df);
	EXPECT_EQ(BigInteger::pow(d, g), dg);
	EXPECT_EQ(BigInteger::pow(d, h), dh);
	EXPECT_EQ(BigInteger::pow(d, i), di);

}


TEST(correctness, addition) {
	BigInteger a = BigInteger::valueOf("2970593235817057278439576704595171194257");
	BigInteger b = BigInteger::valueOf("-529897063810687446911132507016162337984");
	BigInteger c = BigInteger::valueOf("1302709817724767330474735285846445148756");
	BigInteger d = BigInteger::valueOf("-8058231938448257656686015472796206073933");
	
	BigInteger aa = BigInteger::valueOf("5941186471634114556879153409190342388514");
	BigInteger ab = BigInteger::valueOf("2440696172006369831528444197579008856273");
	BigInteger ac = BigInteger::valueOf("4273303053541824608914311990441616343013");
	BigInteger ad = BigInteger::valueOf("-5087638702631200378246438768201034879676");

	BigInteger bb = BigInteger::valueOf("-1059794127621374893822265014032324675968");
	BigInteger bc = BigInteger::valueOf("772812753914079883563602778830282810772");
	BigInteger bd = BigInteger::valueOf("-8588129002258945103597147979812368411917");

	BigInteger cc = BigInteger::valueOf("2605419635449534660949470571692890297512");
	BigInteger cd = BigInteger::valueOf("-6755522120723490326211280186949760925177");

	BigInteger dd = BigInteger::valueOf("-16116463876896515313372030945592412147866");

	EXPECT_EQ(a + a, aa);
	EXPECT_EQ(a + b, ab);
	EXPECT_EQ(a + c, ac);
	EXPECT_EQ(a + d, ad);

	EXPECT_EQ(b + b, bb);
	EXPECT_EQ(b + c, bc);
	EXPECT_EQ(b + d, bd);
	
	EXPECT_EQ(c + c, cc);
	EXPECT_EQ(c + d, cd);
	
	EXPECT_EQ(d + d, dd);

	EXPECT_EQ(b + a, ab);
	EXPECT_EQ(c + a, ac);
	EXPECT_EQ(d + a, ad);

	EXPECT_EQ(c + b, bc);
	EXPECT_EQ(d + b, bd);

	EXPECT_EQ(d + c, cd);
}

TEST(correctness, subtraction) {
	BigInteger a = BigInteger::valueOf("2970593235817057278439576704595171194257");
	BigInteger b = BigInteger::valueOf("-529897063810687446911132507016162337984");
	BigInteger c = BigInteger::valueOf("1302709817724767330474735285846445148756");
	BigInteger d = BigInteger::valueOf("-8058231938448257656686015472796206073933");

	BigInteger ab = BigInteger::valueOf("3500490299627744725350709211611333532241");
	BigInteger ac = BigInteger::valueOf("1667883418092289947964841418748726045501");
	BigInteger ad = BigInteger::valueOf("11028825174265314935125592177391377268190");

	BigInteger ba = BigInteger::valueOf("-3500490299627744725350709211611333532241");
	BigInteger bc = BigInteger::valueOf("-1832606881535454777385867792862607486740");
	BigInteger bd = BigInteger::valueOf("7528334874637570209774882965780043735949");

	BigInteger ca = BigInteger::valueOf("-1667883418092289947964841418748726045501");
	BigInteger cb = BigInteger::valueOf("1832606881535454777385867792862607486740");
	BigInteger cd = BigInteger::valueOf("9360941756173024987160750758642651222689");

	BigInteger da = BigInteger::valueOf("-11028825174265314935125592177391377268190");
	BigInteger db = BigInteger::valueOf("-7528334874637570209774882965780043735949");
	BigInteger dc = BigInteger::valueOf("-9360941756173024987160750758642651222689");

	EXPECT_EQ(a - b, ab);
	EXPECT_EQ(a - c, ac);
	EXPECT_EQ(a - d, ad);

	EXPECT_EQ(b - a, ba);
	EXPECT_EQ(b - c, bc);
	EXPECT_EQ(b - d, bd);

	EXPECT_EQ(c - a, ca); 
	EXPECT_EQ(c - b, cb);
	EXPECT_EQ(c - d, cd);

	EXPECT_EQ(d - a, da);
	EXPECT_EQ(d - b, db);
	EXPECT_EQ(d - c, dc);
}

TEST(correctness, multiplication) {
	BigInteger a = BigInteger::valueOf("2970593235817057278439576704595171194257");
	BigInteger b = BigInteger::valueOf("-529897063810687446911132507016162337984");
	BigInteger c = BigInteger::valueOf("1302709817724767330474735285846445148756");
	BigInteger d = BigInteger::valueOf("-8058231938448257656686015472796206073933");

	BigInteger aa = BigInteger::valueOf("8824424172682054873547818426119105902304139117860017705020700328329303629782049");
	BigInteger ab = BigInteger::valueOf("-1574108633435347703303914869297340447145850631599001582761124495034922553757888");
	BigInteger ac = BigInteger::valueOf("3869820972765665462123973415491484228399922115709866645618119208527152537894292");
	BigInteger ad = BigInteger::valueOf("-23937729288999367649151838067774914101434982696105181793873146921033380847002781");

	BigInteger bb = BigInteger::valueOf("280790898235187763915569211522672919849051780328832609780947712945109049184256");
	BigInteger bc = BigInteger::valueOf("-690302107409710046974271043897432999901622854089618997462823309311111629147904");
	BigInteger bd = BigInteger::valueOf("4270033443689235986543546183252067260338435153658303704786787480150818838171072");

	BigInteger cc = BigInteger::valueOf("1697052869196496522425929538020404651057736347842383866539563500772566968347536");
	BigInteger cd = BigInteger::valueOf("-10497537859719828246285683130730081563675194209610129991173216147427648918977348");

	BigInteger dd = BigInteger::valueOf("64935101973827564175321513168474753612494315174012140717966771894919801862088489");

	EXPECT_EQ(a * a, aa);
	EXPECT_EQ(a * b, ab);
	EXPECT_EQ(a * c, ac);
	EXPECT_EQ(a * d, ad);

	EXPECT_EQ(b * b, bb);
	EXPECT_EQ(b * c, bc);
	EXPECT_EQ(b * d, bd);

	EXPECT_EQ(c * c, cc);
	EXPECT_EQ(c * d, cd);

	EXPECT_EQ(d * d, dd);

	EXPECT_EQ(b * a, ab);
	EXPECT_EQ(c * a, ac);
	EXPECT_EQ(d * a, ad);

	EXPECT_EQ(c * b, bc);
	EXPECT_EQ(d * b, bd);

	EXPECT_EQ(d * c, cd);
}

TEST(correctness, division) {
	BigInteger a = BigInteger::valueOf("2970593235817057278439576704595171194257");
	BigInteger b = BigInteger::valueOf("-529897063810687446911132507016162337984");
	BigInteger c = BigInteger::valueOf("1302709817724767330474735285846445148756");
	BigInteger d = BigInteger::valueOf("-8058231938448257656686015472796206073933");

	BigInteger ab = BigInteger::valueOf("-5");
	BigInteger ac = BigInteger::valueOf("2");
	BigInteger ad = BigInteger::valueOf("0");

	BigInteger ba = BigInteger::valueOf("0");
	BigInteger bc = BigInteger::valueOf("0");
	BigInteger bd = BigInteger::valueOf("0");

	BigInteger ca = BigInteger::valueOf("0");
	BigInteger cb = BigInteger::valueOf("-2");
	BigInteger cd = BigInteger::valueOf("0");

	BigInteger da = BigInteger::valueOf("-2");
	BigInteger db = BigInteger::valueOf("15");
	BigInteger dc = BigInteger::valueOf("-6");


	EXPECT_EQ(a / b, ab);
	EXPECT_EQ(a / c, ac);
	EXPECT_EQ(a / d, ad);

	EXPECT_EQ(b / a, ba);
	EXPECT_EQ(b / c, bc);
	EXPECT_EQ(b / d, bd);

	EXPECT_EQ(c / a, ca);
	EXPECT_EQ(c / b, cb);
	EXPECT_EQ(c / d, cd);

	EXPECT_EQ(d / a, da);
	EXPECT_EQ(d / b, db);
	EXPECT_EQ(d / c, dc);
}

TEST(correctness, divisionWithMod) {
	BigInteger a = BigInteger::valueOf("8744032348991927327485206610290159808270");
	BigInteger b = BigInteger::valueOf("715819475286141097719228188666642191129");
	BigInteger c = BigInteger::valueOf("1445619970731680191864132582034832344529");
	BigInteger d = BigInteger::valueOf("3115683533950032767575510636163566127724");

	BigInteger ab = BigInteger::valueOf("154198645558234154854468346290453514722");
	BigInteger ac = BigInteger::valueOf("70312524601846176300411118081165741096");
	BigInteger ad = BigInteger::valueOf("2512665281091861792334185337963027552822");


	EXPECT_EQ(a % b, ab);
	EXPECT_EQ(a % c, ac);
	EXPECT_EQ(a % d, ad);
}

TEST(correctness, pow) {
	BigInteger a = BigInteger::valueOf("123423");
	BigInteger b = BigInteger::valueOf("-7426");
	BigInteger c = BigInteger::valueOf("722");

	long long d = 9;
	long long e = 32;
	long long f = 76;
	long long g = 10;

	BigInteger ae = BigInteger::valueOf("8407660186888674435541605219145228335439162092761026939816\
323223832523393441449400661971103996952439572128590369230539134191453066696173713290023773132859683077121");

	BigInteger ag = BigInteger::valueOf("820277850155770430378575843168548097665874812755649");

	BigInteger cf = BigInteger::valueOf("17734829406354043080527083200497126394136508565348445985766848859800376\
016428325015545788334469727074761525505654641782908084827285200083179080\
125180187183356386338022037305344235281417624442401940024114609669428740096");

	BigInteger bd = BigInteger::valueOf("-68674341536844455979663679379800576");

	EXPECT_EQ(BigInteger::pow(a, e), ae);
	EXPECT_EQ(BigInteger::pow(a, g), ag);
	EXPECT_EQ(BigInteger::pow(c, f), cf);
	EXPECT_EQ(BigInteger::pow(b, d), bd);

}


int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
