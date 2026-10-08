module dffreset_tb;
    reg in, reset, clk;
    wire out;

    // Instantiate the design
    dffreset uut (
        .in(in),
        .reset(reset),
        .clk(clk),
        .out(out)
    );

    // Generate a clock signal with a period of 10 units
    always #5 clk = ~clk;

    initial begin
        // Generate the VCD file for GTKWave
        $dumpfile("dff_test.vcd");
        $dumpvars(0, dffreset_tb);

        // Initialize signals
        clk = 0; reset = 1; in = 1;
        
        // Apply test vectors
        #10 reset = 1; in = 0;
        #10 reset = 0; in = 1;
        #10 reset = 0; in = 0;
        #10 reset = 0; in = 1;
        
        #10 $finish; // End simulation
    end

    // Monitor output in the console
    initial begin
        $monitor("%0t clk=%b, reset=%b, in=%b, out=%b", $time, clk, reset, in, out);
    end
endmodule