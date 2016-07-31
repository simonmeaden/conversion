#include <QString>
#include <QtTest>

//#include "conversion.h"
#include "biginteger.h"

class TestConversion : public QObject {
        Q_OBJECT

    public:
        TestConversion();
        ~TestConversion();

    private Q_SLOTS:
        //        void testInchesToMetres();
        void testFromDecimal_data();
        void testFromDecimal();
        void testFromBinary_data();
        void testFromBinary();

        void initTestCase() ;
        void cleanupTestCase();
        void init();
        void cleanup();

};

TestConversion::TestConversion() {

}

TestConversion::~TestConversion() {

}

//void TestConversion::testInchesToMetres() {
//    double result;
//    result = Conversion::convert( Conversion::Inches, Conversion::Metres, 10.0 );
//    QCOMPARE( 0.254, result );
//    result = Conversion::convert( Conversion::Inches, Conversion::Metres, 100.0 );
//    QCOMPARE( 2.54, result );
//}

void TestConversion::initTestCase() {

}

void TestConversion::cleanupTestCase() {

}

void TestConversion::init() {
}

void TestConversion::cleanup() {

}

QTEST_APPLESS_MAIN( TestConversion )

#include "tst_testconversion.moc"
