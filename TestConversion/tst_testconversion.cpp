#include <QString>
#include <QtTest>

class TestConversion : public QObject
{
    Q_OBJECT

public:
    TestConversion();

private Q_SLOTS:
    void testCase1();
};

TestConversion::TestConversion()
{
}

void TestConversion::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestConversion)

#include "tst_testconversion.moc"
