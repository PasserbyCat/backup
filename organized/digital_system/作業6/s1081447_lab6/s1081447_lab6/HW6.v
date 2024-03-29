module HW6(sw, led);
	input [9:0]sw;
	output [9:0]led;
	reg [9:0]led;
	always @(sw)
		led[9:0] <= sw[9:0];
endmodule 