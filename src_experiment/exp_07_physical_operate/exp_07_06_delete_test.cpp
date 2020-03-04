//
// Created by maokw on 2020-03-04.
//

#include <cstdio>
#include <gtest/gtest.h>
#include <test/test_stmt_parser.h>
#include <test/test_physical_operate.h>

class Exp_01_05_DeleteTest : public TestPhysicalOperate {
protected:

    void SetUp() override {
        _m_list[0] = "delete student where sname = 'tom simith'";
        _m_list[1] = "select * from student where sname = 'tom simith'";
        _m_list[2] = "delete student where sno = '2012010102'";
        _m_list[3] = "select *  from student where sno = '2012010102'";
        _m_list[4] = "delete student  where sname = 'john simith' and ssex='male'";
        _m_list[5] = "select *  from student  where sname = 'john simith' and ssex='male'";
        _m_list[6] = "delete sc where sno = '2012010103' ";
        _m_list[7] = "select *  from sc where sno = '2012010103' ";
        _m_list[8] = "delete sc  where grade >= 80 and cno = 'c003'";
        _m_list[9] = "select *  from sc  where grade >= 80 and cno = 'c003'";
    }

    const char *_m_list[11]{};
    const char *dbname = "test_demodb";
};

TEST_F(Exp_01_05_DeleteTest, Correct) {
    try {
        createDB(dbname);
        createTable();
        insertData();

        EXPECT_EQ(1, delete_(_m_list[0]));
        EXPECT_EQ(0, select(_m_list[1]));
        EXPECT_EQ(1, delete_(_m_list[2]));
        EXPECT_EQ(0, select(_m_list[3]));
        EXPECT_EQ(1, delete_(_m_list[4]));
        EXPECT_EQ(0, select(_m_list[5]));
        EXPECT_EQ(2, delete_(_m_list[6]));
        EXPECT_EQ(0, select(_m_list[7]));
        EXPECT_EQ(3, delete_(_m_list[8]));
        EXPECT_EQ(0, select(_m_list[9]));

        dropDB();
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }
}