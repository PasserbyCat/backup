module FA(X, Y, Z, S, C);

input X, Y, Z;
output S, C;
wire bufx, a1, a2;
 
assign bufx = X ^ Y;
assign a1 = X & Y;
assign a2 = Z & bufx;
assign S = bufx ^ Z;
assign C = a1 | a2;

endmodule

module lab7(a, b, Cin, Sum, A, B,C1,C2);
input [2:0]a;
input [2:0]b;
input Cin;
output [3:0]Sum;
output [7:0]A,B,C1,C2;
reg [7:0]A,B,C1,C2;
wire c1, c2;

FA mod1(.X(a[0]), .Y(b[0]), .Z(Cin), .S(Sum[0]), .C(c1));
FA mod2(.X(a[1]), .Y(b[1]), .Z(c1), .S(Sum[1]), .C(c2));
FA mod3(.X(a[2]), .Y(b[2]), .Z(c2), .S(Sum[2]), .C(Sum[3]));

always @(a)
	begin 
		case (a)
			default:
				begin
					A=8'b11000000;
				end
			4'b0001:
				begin
					A=8'b11111001;
				end
			4'b0010:
				begin
					A=8'b10100100;
				end
			4'b0011:
				begin
					A=8'b10110000;
				end
			4'b0100:
				begin
					A=8'b10011001;
				end
			4'b0101:
				begin
					A=8'b10010010;
				end
			4'b0110:
				begin
					A=8'b10000010;
				end
			4'b0111:
				begin
					A=8'b11111000;
				end
		endcase
	end

always @(b)
	begin 
		case (b)
			default:
				begin
					B=8'b11000000;
				end
			4'b0001:
				begin
					B=8'b11111001;
				end
			4'b0010:
				begin
					B=8'b10100100;
				end
			4'b0011:
				begin
					B=8'b10110000;
				end
			4'b0100:
				begin
					B=8'b10011001;
				end
			4'b0101:
				begin
					B=8'b10010010;
				end
			4'b0110:
				begin
					B=8'b10000010;
				end
			4'b0111:
				begin
					B=8'b11111000;
				end
		endcase
	end
	
always @(Sum)
	begin 
		case (Sum)
			default:
				begin
					C1=8'b11000000;
					C2=8'b11000000;
				end
			4'b0001:
				begin
					C1=8'b11000000;
					C2=8'b11111001;
				end
			4'b0010:
				begin
					C1=8'b11000000;
					C2=8'b10100100;
				end
			4'b0011:
				begin
					C1=8'b11000000;
					C2=8'b10110000;
				end
			4'b0100:
				begin
					C1=8'b11000000;
					C2=8'b10011001;
				end
			4'b0101:
				begin
					C1=8'b11000000;
					C2=8'b10010010;
				end
			4'b0110:
				begin
					C1=8'b11000000;
					C2=8'b10000010;
				end
			4'b0111:
				begin
					C1=8'b11000000;
					C2=8'b11111000;
				end
			4'b1000:
				begin
					C1=8'b11000000;
					C2=8'b10000000;
				end
			4'b1001:
				begin
					C1=8'b11000000;
					C2=8'b10010000;
				end
			4'b1010:
				begin
					C1=8'b11111001;
					C2=8'b11000000;
				end
			4'b1011:
				begin
					C1=8'b11111001;
					C2=8'b11111001;
				end
			4'b1100:
				begin
					C1=8'b11111001;
					C2=8'b10100100;
				end
			4'b1101:
				begin
					C1=8'b11111001;
					C2=8'b10110000;
				end
			4'b1110:
				begin
					C1=8'b11111001;
					C2=8'b10011001;
				end
			4'b1111:
				begin
					C1=8'b11111001;
					C2=8'b10010010;
				end
		endcase
	end
endmodule 
