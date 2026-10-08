module decoder2to4_tb;

    // Inputs are reg
    reg X;
    reg Y;

    // Outputs are wire
    wire F0, F1, F2, F3;

    // Instantiate the decoder
    decoder2to4 uut (
        .X(X),
        .Y(Y),
        .F0(F0),
        .F1(F1),
        .F2(F2),
        .F3(F3)
    );

    initial begin
        // Generate waveform file for GTKWave
        $dumpfile("decoder_waves.vcd");
        $dumpvars(0, decoder2to4_tb);

        // Apply test vectors matching the truth table
        X = 0; Y = 0; #10;
        X = 0; Y = 1; #10;
        X = 1; Y = 0; #10;
        X = 1; Y = 1; #10;

        // End simulation
        $finish;
    end

    // Monitor changes in the console
    initial begin
        $monitor("Time=%0t | X=%b Y=%b || F0=%b F1=%b F2=%b F3=%b", 
                 $time, X, Y, F0, F1, F2, F3);
    end

endmodule