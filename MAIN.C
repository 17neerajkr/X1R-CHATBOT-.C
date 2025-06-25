#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;

    // Open database (creates new if doesn't exist)
    int rc = sqlite3_open("x1r_database.db", &db);

    if (rc) {
        printf("❌ Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("✅ Opened database successfully.\n");
    }

    // SQL to create table
    char *sql = "CREATE TABLE IF NOT EXISTS Students (ID INT PRIMARY KEY, Name TEXT);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        printf("❌ SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("✅ Table created successfully.\n");
    }

    sqlite3_close(db);
    return 0;
}

