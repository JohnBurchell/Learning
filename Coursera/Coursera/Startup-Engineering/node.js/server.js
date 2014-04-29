var http = require("http");
var fs = require("fs");

http.createServer(function(request, response) {
	
	response.writeHead(200, {"Content-Type": "text/plain"});
	var out = fs.readFileSync("index.html");
	response.write(out.toString());
	response.end();

}).listen(8888);