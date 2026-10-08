module fulladder_tb;
    wire sum, carry;
    reg a, b, c;
    full_adder fa1(sum, carry, a, b, c);

    initial
    begin
        #000000 a=0; b=0; c=0;
        #100 a=0; b=0; c=1;
        #100 a=0; b=1; c=0;
        #100 a=0; b=1; c=1;
        #100 a=1; b=0; c=0;
        #100 a=1; b=0; c=1;
        #100 a=1; b=1; c=0;
        #100 a=1; b=1; c=1;
    end
    initial
    begin
        $monitor($time, "a=%b, b=%b, c=%b, sum=%b, carry=%b", a, b, c, sum, carry);
    end
    initial
    begin
        $dumpfile("full_adder.vcd");
        $dumpvars(0, fulladder_tb);
    end
    
    
endmodule