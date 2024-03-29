library verilog;
use verilog.vl_types.all;
entity FA is
    port(
        A               : in     vl_logic;
        B               : in     vl_logic;
        S               : out    vl_logic;
        C_in            : in     vl_logic;
        C_out           : out    vl_logic
    );
end FA;
