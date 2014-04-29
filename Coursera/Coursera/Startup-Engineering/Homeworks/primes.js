#!/usr/bin/env node

//Using Eratosthenes sieve
//http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

var startSeive = function(e) {

	var primes = [];
	var notMarked = [];
	var numbers = [];
	var count = 0;

	for (var i = 0; i < e; i++) {

		notMarked[i] = true;
	}

	for (var i = 2; i < e; i++) {

		if(notMarked[i] == true) {

			var iroot = Math.sqrt(i) + 1;

			for (var p = (i * i); p < e; p += i) {

				notMarked[p] = false;

			}

		}
	}

	var outString = "";
	console.log("The following are the prime numbers up to 250");
	for (var i = 2; i < e && count != 100; i++) {

		if (notMarked[i] == true) {

			count ++;
			console.log(i);
			outString += (i + ",");
		}
	}

	console.log(outString);
	var ffs = require('fs');
	var outputFile = "primes.txt";
	ffs.writeFileSync(outputFile, outString);

}

startSeive(10000);


