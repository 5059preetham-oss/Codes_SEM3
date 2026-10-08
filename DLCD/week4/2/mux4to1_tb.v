module mux4x1_tb;

    // Inputs
    reg I0, I1, I2, I3;
    reg S1, S0;

    // Outputs
    wire f;

    // Instantiate the Unit Under Test (UUT)
    mux4x1 uut (
        .I0(I0), 
        .I1(I1), 
        .I2(I2), 
        .I3(I3),
        .S0(S0), 
        .S1(S1),
        .f(f)
    );

    initial begin
        // Generate waveform file for GTKWave
        $dumpfile("mux4x1_waves.vcd");
        $dumpvars(0, mux4x1_tb);

        // --- TEST CASE 1 ---
        // Give inputs alternating values to easily track them
        I0 = 1; I1 = 0; I2 = 1; I3 = 0;
        
        $display("Testing Pattern: I0=%b, I1=%b, I2=%b, I3=%b", I0, I1, I2, I3);
        S1 = 0; S0 = 0; #10; // Selects I0 -> f should be 1
        S1 = 0; S0 = 1; #10; // Selects I1 -> f should be 0
        S1 = 1; S0 = 0; #10; // Selects I2 -> f should be 1
        S1 = 1; S0 = 1; #10; // Selects I3 -> f should be 0

        // --- TEST CASE 2 ---
        // Invert the inputs to ensure it's not a fluke
        I0 = 0; I1 = 1; I2 = 0; I3 = 1;
        
        $display("Testing Pattern: I0=%b, I1=%b, I2=%b, I3=%b", I0, I1, I2, I3);
        S1 = 0; S0 = 0; #10; // Selects I0 -> f should be 0
        S1 = 0; S0 = 1; #10; // Selects I1 -> f should be 1
        S1 = 1; S0 = 0; #10; // Selects I2 -> f should be 0
        S1 = 1; S0 = 1; #10; // Selects I3 -> f should be 1

        $finish;
    end

    // Monitor changes
    initial begin
        $monitor("Time=%0t | S1=%b S0=%b || Output f=%b", $time, S1, S0, f);
    end

endmodule