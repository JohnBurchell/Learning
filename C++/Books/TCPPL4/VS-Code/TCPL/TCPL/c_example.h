#include <iostream>
#include <fstream>
#include <string>
#include <array>

const int MAX_DATA = 512;
const int MAX_ROWS = 100;

struct Address {
	int id;
	int set;
	std::string name;
	std::string email;
};

struct Database {
	int max_rows;
	int max_data;
	std::array<struct Address, MAX_ROWS> rows;
};

struct Connection {

	std::fstream file;
	struct Database *db;
};

void die(const std::string, struct Connection *conn);
void Address_print(struct Address *addr);

struct Connection *Database_open(const char *filename, char mode);

void Database_load(struct Connection *conn);
void Database_close(struct Connection *conn);
void Database_write(struct Connection *conn);
void Database_create(struct Connection *conn);
void Database_set(struct Connection *conn, int id, const char *name, const char *email);
void Database_get(struct Connection *conn, int id);
void Database_delete(struct Connection *conn, int id);
void Database_list(struct Connection *conn);
