#include <LuteBase.h>
#include <LuteMySQL.h>

#include <thread>

using namespace Lute::mysql;

int main() {
    initLogger(Lute::Logger::LogLevel::DEBUG);

    auto connpool = MySQLConnPool::getInstance();
    connpool->init(10, "192.168.1.106", 3306, "lutianen", "lutianen",
                   "LuxDatabase");

    std::thread t1([&] {
        MYSQL* mysql = nullptr;
        MySQLConn conn(mysql, connpool);
        conn.execute("SELECT * FROM user;");

        LOG_INFO << conn.stmtRes_.numFields_;
        for (auto& row : conn.stmtRes_.rows_) {
            for (int i = 0; i < conn.stmtRes_.numFields_; i++) {
                LOG_INFO << row[i];
            }
        }
    });

    t1.join();

    return 0;
}
