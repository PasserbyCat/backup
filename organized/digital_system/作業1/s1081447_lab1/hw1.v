module hw1(x, y, V, d0, d1, d2, d3);
	input d0, d1, d2, d3;
	output x, y, V;
	wire out_n1, out_a1;
	
	or or1(x, d2, d3);
	
	not not1(out_n1, d2);
	and and1(out_a1, out_n1, d1);
	or or2(y, out_a1, d3); 
	
	or or3(V, x, d1, d0);
	
endmodule
