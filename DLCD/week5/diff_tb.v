module dff_tb;
    reg IN, CLK;
    wire OUT, OUT_bar;

    // Instantiate the simple D flip-flop
    dff uut (
        .IN(IN),
        .CLK(CLK),
        .OUT(OUT),
        .OUT_bar(OUT_bar)
    );

    // 10-unit clock period
    always #5 CLK = ~CLK;

    initial begin
        $dumpfile("dff_test.vcd");
        $dumpvars(0, dff_tb);

        // Initial states
        CLK = 0; IN = 1;
        
        // Apply inputs matching your execution log
        #5 IN = 0;
        #5 IN = 1;
        #5 IN = 1;
        #5 IN = 0;
        #5 IN = 0;
        #5 IN = 1;
        #5 IN = 1;
        #5 IN = 0;
        
        #10 $finish;
    end
endmodule