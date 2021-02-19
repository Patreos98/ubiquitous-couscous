// show the difference between calling a short js function
// relative to a comparable C++ function.
// Reports millions of calls per second.
// Note that JS speed goes up, while cxx speed stays about the same.
'use strict';

const assert = require('assert');
const common = require('../../common.js');

// this fails when we try to open with a different version of node,
// which is quite common for benchmarks.  so in that case, just
// abort quietly.

try {
  var binding = require('./build/Release/binding');
} catch (er) {
  console.error('misc/function_call.js Binding failed to load');
  process.exit(0);
}
const cxx = binding.hello;

var c = 0;
function js() {
  return c++;
}

assert(js() === cxx());

const bench = common.createBenchmark(main, {
  type: ['js', 'cxx'],
  millions: [1, 10, 50]
});

function main({ millions, type }) {
  const fn = type === 'cxx' ? cxx : js;
  bench.start();
  for (var i = 0; i < millions * 1e6; i++) {
    fn();
  }
  bench.end(millions);
}
