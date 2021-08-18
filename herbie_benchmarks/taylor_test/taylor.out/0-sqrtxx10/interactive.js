function fmax(x, y) { if (x != x) { return y; } else if (y != y) { return x; } else { return Math.max(x, y); }}
function fmin(x, y) { if (x != x) { return y; } else if (y != y) { return x; } else { return Math.min(x, y); }}
function pow(x, y) { if (x == 1.0 && isNaN(y)) { return 1.0; } else { return Math.pow(x, y); }}
function fdim(x , y) { if (x != x || y != y) { return NaN; } else if (x > y) { return x - y; } else { return 0; }}

function start(x) {
	return Math.sqrt((x * x) + 1.0);
}
function end(x) {
	var tmp;
	if (x <= -1.3366836797255362e+154) {
		tmp = (0.125 / pow(x, 3.0)) - (x + (0.5 / x));
	} else if (x <= 3835.827149827554) {
		tmp = Math.sqrt((x * x) + 1.0);
	} else {
		tmp = (x + (0.5 / x)) - (0.125 / pow(x, 3.0));
	}
	return tmp;
}
