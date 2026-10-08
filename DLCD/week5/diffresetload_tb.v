module dffresetload_tb;
    reg in, load, reset, CLK;
    wire out;

    // Instantiate the resettable load D flip-flop
    dffresetload uut (
        .in(in),
        .load(load),
        .reset(reset),
        .CLK(CLK),
        .out(out)
    );

    // 10-unit clock period
    always #5 CLK = ~CLK;

    initial begin
        $dumpfile("dff_test.vcd");
        $dumpvars(0, dffresetload_tb);

        // Initial state (Reset active)
        CLK = 0; reset = 1; load = 0; in = 1;
        
        // Sequence demonstrating holding, loading, and resetting
        #10 reset = 1; load = 0; in = 1;
        #10 reset = 0; load = 0; in = 1; // Hold previous (0)
        #10 reset = 0; load = 1; in = 0; // Load 0
        #10 reset = 0; load = 1; in = 1; // Load 1
        #10 reset = 0; load = 0; in = 0; // Hold previous (1)
        
        #10 $finish;
    end
endmodule