module plus(in_1, in_2, in_3, out_1, out_2);
	input in_1, in_2, in_3;
	output out_1, out_2;
	assign out_2 = in_1 ^ in_2 ^ in_3;
	assign out_1 = ((in_1 ^ in_2) & in_3) | (in_1 & in_2);
endmodule

module hw2(a, b, c_in, c_out, sum);
	input [3:0] a,b;
	input c_in;
	output c_out;
	wire [3:0] c;
	output [3:0] sum;
	plus mod0(a[0], b[0], c_in, c[0], sum[0]);
	plus mod1(a[1], b[1], c[0], c[1], sum[1]);
	plus mod2(a[2], b[2], c[1], c[2], sum[2]);
	plus mod3(a[3], b[3], c[2], c_out, sum[3]);
endmodule
