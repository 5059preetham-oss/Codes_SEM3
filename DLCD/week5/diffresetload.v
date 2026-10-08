module dffresetload (
    input in,
    input load,
    input reset,
    input CLK,
    output reg out
);
    wire mux_out;
    wire d_in;

    // 2x1 MUX: Select 'in' when load=1, feedback 'out' when load=0
    assign mux_out = load ? in : out;

    // AND gate with inverted reset
    assign d_in = mux_out & (~reset);

    // Trigger on positive edge of the clock
    always @(posedge CLK) begin
        out <= d_in;
    end
endmodule