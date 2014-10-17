#include "c_example.h"

using namespace std;

void die(const string message, struct Connection *conn)
{
	if (errno) {
		cerr << message;
	}
	else {
		cout << "ERROR: " << message << endl;
	}

	Database_close(conn);
	exit(1);
}

void Address_print(struct Address *addr)
{
	cout << addr->id << " " << addr->name << " " << addr->email << endl;
}

void Database_load(struct Connection *conn)
{
	streamsize rc = conn->file.gcount();
	if (rc < 0) die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = new struct Connection;
	if (!conn) die("Memory error", conn);

	conn->db = new struct Database;
	if (!conn->db) die("Memory error", conn);

	else {

		conn->file.open(filename, ios_base::in | ios_base::out | ios_base::app);

		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file) die("Failed to open the file", conn);

	return conn;
}

void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn->file) conn->file.close();
		if (conn->db) delete(conn->db);
		delete(conn);
	}
}

void Database_write(struct Connection *conn)
{
	//Seek to front of file
	conn->file.seekg(0, conn->file.beg);

	//write
	conn->file << conn->db;

	if (!conn->file) die("Failed to write database.", conn);

	conn->file.flush();
	if (!conn->file) die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = { addr.id = i, addr.set = 0 };
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if (addr->set) die("Already set, delete it first", conn);

	addr->set = 1;

	addr->name = name;
	if (addr->name != name) die("Email copy failed", conn);
	addr->email = email;
	if (addr->email != email) die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	}
	else {
		die("ID is not set", conn);
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = { addr.id = id, addr.set = 0 };
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int mains(int argc, char *argv[])
{

	if (argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", nullptr);

	char *filename = argv[1];
	char action = argv[2][0];
	int id = 0;
	struct Connection *conn = Database_open(filename, action);


	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.", conn);

	switch (action) {
	case 'c':
		if (argc != 4) die("Need max_rows to create", conn);
		Database_create(conn);
		Database_write(conn);
		break;
	case 'g':
		if (argc != 4) die("Need an id to get", conn);

		Database_get(conn, id);
		break;

	case 's':
		if (argc != 6) die("Need id, name, email to set", conn);

		Database_set(conn, id, argv[4], argv[5]);
		Database_write(conn);
		break;

	case 'd':
		if (argc != 4) die("Need to delete", conn);

		Database_delete(conn, id);
		Database_write(conn);
		break;

	case 'l':
		Database_list(conn);
		break;
	default:
		die("Invalid action, only: c=create, g=get, d=del, l=list", conn);

	}

	Database_close(conn);

	system("pause");
	return 0;
}




