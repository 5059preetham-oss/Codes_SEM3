module ripple_tb;

reg [3:0] a, b;
reg cin1;
wire [3:0] s;
wire cout;

rippleca r1(a, b, cin1, s, cout);

initial
begin
    $dumpfile("ripple.vcd");
    $dumpvars(0, ripple_tb);

    $monitor("%0t a=%b b=%b cin=%b s=%b cout=%b",
             $time, a, b, cin1, s, cout);

    a=4'b0000; b=4'b0000; cin1=0;
    #10 a=4'b0011; b=4'b0101; cin1=0;
    #10 a=4'b0111; b=4'b0001; cin1=0;
    #10 a=4'b1111; b=4'b0001; cin1=0;
    #10 a=4'b1010; b=4'b0101; cin1=1;
    #10 a=4'b1111; b=4'b1111; cin1=1;

    #10 $finish;
end

endmodule