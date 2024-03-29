module mgs(s, apple, button, banana, seven1, seven10, seven100);
	input [3:0]s;
	
	input [5:0]apple;
	output reg [9:0]banana;
	
	input [2:0]button;
	output reg [7:0]seven1;
	output reg [7:0]seven10;
	output reg [7:0]seven100;
	reg init;
	reg [3:0]number1;
	reg [3:0]number10;
	reg [3:0]number100;
	reg [1:0]locate;
	reg stop1;
	reg stop2;
	reg stop0;
	reg [3:0]answer1;
	reg [3:0]answer10;
	reg [3:0]answer100;

	always @(s, apple, button)
		begin
			case (s)
            default:
                begin
					banana = 10'b0000000000;
					init = 0;
					seven1 = 8'b11111111;
					seven10 = 8'b111111111;
					seven100 = 8'b111111111;
					locate = 2'b10;
					stop1 = 0;
					stop2 = 0;
					stop0 = 1;
					answer1 = 1;
					answer10 = 2;
					answer100 = 3;
                end
            4'b0001:
				begin
					if (apple == 6'b100100)banana = 10'b1111111111;
					else if (apple == 6'b100010)banana = 10'b0000011111;
					else if (apple == 6'b100001)banana = 10'b1111100000;
					else if (apple == 6'b010100)banana = 10'b1111100000;
					else if (apple == 6'b010010)banana = 10'b1111111111;
					else if (apple == 6'b010001)banana = 10'b0000011111;
					else if (apple == 6'b001100)banana = 10'b0000011111;
					else if (apple == 6'b001010)banana = 10'b1111100000;
					else if (apple == 6'b001001)banana = 10'b1111111111;
					else banana = 10'b0000000000;
				end
            4'b0010:
                begin
					if (init == 0) 
					begin 
						number1 = 4'b0000; 
						number10 = 4'b0000;
						number100 = 4'b0000;
						init = 1;
						seven1 = 8'b11000000;
						seven10 = 8'b11000000;
						seven100 = 8'b11000000;
						banana = 10'b0000000000;
					end
					//button2
					if (button[2] == 1'b1 && stop2 == 0)
						begin
							stop2 = 1;
							if (locate == 0) number1 = (number1 + 1) % 10;
							else if (locate == 1) number10 = (number10 + 1) % 10;
							else if (locate == 2) number100 = (number100 + 1) % 10;
						end
					if (button[2] == 1'b0) stop2 = 0;
					//button1
					if (button[1] == 1'b1 && stop1 == 0)
						begin
							stop1 = 1;
							locate = (locate + 1) % 3;
						end
					if (button[1] == 1'b0) stop1 = 0;
					//button0
					if (button[0] == 1'b1 && stop0 == 0)
						begin
							stop0 = 1;
							if (answer100 < number100) banana = 10'b1111100000;
							else if (answer100 > number100) banana = 10'b0000011111;
							else if (answer10 < number10) banana = 10'b1111100000;
							else if (answer10 > number10) banana = 10'b0000011111;
							else if (answer1 < number1) banana = 10'b1111100000;
							else if (answer1 > number1) banana = 10'b0000011111;
							else  banana = 10'b1111111111;
						end
					if (button[0] == 1'b0) stop0 = 0;
					
					if (init == 1)
					begin
					if (number10 == 0) seven10 <= 8'b11000000;
					if (number10 == 1) seven10 <= 8'b11111001;
					if (number10 == 2) seven10 <= 8'b10100100;
					if (number10 == 3) seven10 <= 8'b10110000;
					if (number10 == 4) seven10 <= 8'b10011001;
					if (number10 == 5) seven10 <= 8'b10010010;
					if (number10 == 6) seven10 <= 8'b10000010;
					if (number10 == 7) seven10 <= 8'b11111000;
					if (number10 == 8) seven10 <= 8'b10000000;
					if (number10 == 9) seven10 <= 8'b10010000;
					
					if (number1 == 0) seven1 = 8'b11000000;
					else if (number1 == 1) seven1 = 8'b11111001;
					else if (number1 == 2) seven1 = 8'b10100100;
					else if (number1 == 3) seven1 = 8'b10110000;
					else if (number1 == 4) seven1 = 8'b10011001;
					else if (number1 == 5) seven1 = 8'b10010010;
					else if (number1 == 6) seven1 = 8'b10000010;
					else if (number1 == 7) seven1 = 8'b11111000;
					else if (number1 == 8) seven1 = 8'b10000000;
					else if (number1 == 9) seven1 = 8'b10010000;
					
					if (number100 == 0) seven100 <= 8'b11000000;
					else if (number100 == 1) seven100 <= 8'b11111001;
					else if (number100 == 2) seven100 <= 8'b10100100;
					else if (number100 == 3) seven100 <= 8'b10110000;
					else if (number100 == 4) seven100 <= 8'b10011001;
					else if (number100 == 5) seven100 <= 8'b10010010;
					else if (number100 == 6) seven100 <= 8'b10000010;
					else if (number100 == 7) seven100 <= 8'b11111000;
					else if (number100 == 8) seven100 <= 8'b10000000;
					else if (number100 == 9) seven100 <= 8'b10010000;
					end
                end
            4'b0100:
                begin

                end
            4'b1000:
				begin

				end
			endcase
	end

endmodule
