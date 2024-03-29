module FSM(str_in, str_out, match, clk, rst);
	input str_in, clk, rst;
	output match;
	output [2:0]str_out;
	reg [2:0]str_out;
	reg [1:0]current_state, next_state;
	reg match;
	parameter state0 = 0, state1 = 1, state2 = 2, state3 = 3;
	
	always@(posedge clk or posedge rst)
		begin //CS
			if(rst) 
				begin
					current_state <= state0;
					str_out[0] <= 0;
					str_out[1] <= 0;
					str_out[2] <= 0;
				end
			else 
				begin
					current_state <= next_state;
					str_out[0] <= str_in;
					str_out[1] <= str_out[0];
					str_out[2] <= str_out[1];
				end
		end	
	
	always@(current_state or str_in)
		begin //NS
			case(current_state)
			state0:
			next_state = (str_in==0)?state0:state1;
			state1:
			next_state = (str_in==0)?state0:state2;
			state2:
			next_state = (str_in==0)?state3:state2;
			state3:
			next_state = (str_in==0)?state0:state1;
			endcase
		end
	
	always@(current_state or str_in)
		begin //OL
			case(current_state)
			state0:match = 0;
			state1:match = 0;
			state2:match = 0;
			state3:match = 1;
			endcase
		end
endmodule
