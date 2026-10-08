module dff (
    input IN,
    input CLK,
    output reg OUT,
    output OUT_bar
);
    // Inverted output logic
    assign OUT_bar = ~OUT;

    // Trigger on positive edge of the clock
    always @(posedge CLK) begin
        OUT <= IN;
    end
endmodule