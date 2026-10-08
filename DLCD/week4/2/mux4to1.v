// Base 2:1 MUX Module
module mux2x1 (
    input wire a,
    input wire b,
    input wire s,
    output wire y
);
    assign y = s ? b : a;
endmodule

// Top-level 4:1 MUX Module
module mux4x1 (
    input wire I0,
    input wire I1,
    input wire I2,
    input wire I3,
    input wire S0,  // LSB
    input wire S1,  // MSB
    output wire f
);

    // Internal wires connecting the first stage to the second stage
    wire mux_top_out;
    wire mux_bot_out;

    // First Stage Instantiations
    // Top MUX (controlled by S0)
    mux2x1 M1 (
        .a(I0), 
        .b(I1), 
        .s(S0), 
        .y(mux_top_out)
    );

    // Bottom MUX (controlled by S0)
    mux2x1 M2 (
        .a(I2), 
        .b(I3), 
        .s(S0), 
        .y(mux_bot_out)
    );

    // Second Stage Instantiation
    // Final MUX (controlled by S1)
    mux2x1 M3 (
        .a(mux_top_out), 
        .b(mux_bot_out), 
        .s(S1), 
        .y(f)
    );

endmodule