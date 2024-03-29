module hw3 (D , clk , enable , seed);
	input clk, enable, seed;
	output [5:0] D;
	reg [5:0] D;
	always @(posedge clk)
	begin
		D[1] <= D[0];
		D[2] <= D[1];
		D[3] <= D[2];
		D[4] <= D[3];
		D[5] <= D[4];
		if (enable)
			D[0] <= seed;
		else 
			D[0] <= D[4] ^ D[5];
	end
endmodule
