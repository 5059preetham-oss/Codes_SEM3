module tb_reg_file;
    reg clk, reset, wr;
    reg [2:0] rd_addr_a, rd_addr_b, wr_addr;
    reg [15:0] d_in;
    wire [15:0] d_out_a, d_out_b;

    // Instantiate the Register File
    reg_file uut (
        .clk(clk), .reset(reset), .wr(wr),
        .rd_addr_a(rd_addr_a), .rd_addr_b(rd_addr_b), .wr_addr(wr_addr),
        .d_in(d_in), 
        .d_out_a(d_out_a), .d_out_b(d_out_b)
    );

    // Clock generation
    always #5 clk = ~clk;

    initial begin
        // For GTKWave output
        $dumpfile("tb_reg_file.vcd");
        $dumpvars(0, tb_reg_file);
        
        // Exact formatting matching your terminal output
        $monitor(" wr=%b rd_addr_a=%bx rd_addr_b=%bx wr_addr =%d  d_in=%h | d_out_a= %h,d_out_b=%h", 
                  wr, rd_addr_a, rd_addr_b, wr_addr, d_in, d_out_a, d_out_b);

        // Initialization & Reset
        clk = 0; reset = 1; wr = 0;
        rd_addr_a = 3'bx; rd_addr_b = 3'bx; wr_addr = 3'bx; d_in = 16'hxxxx;
        #10 reset = 0;
        
        // Test sequence replicating the assignment GTKWave output
        #10 wr=1; rd_addr_a=3'bx; rd_addr_b=3'bx; wr_addr=3; d_in=16'hcdef;
        #10 wr=1; rd_addr_a=3'bx; rd_addr_b=3'bx; wr_addr=7; d_in=16'h3210;
        #10 wr=1; rd_addr_a=3'bx; rd_addr_b=7;    wr_addr=5; d_in=16'h4567;
        
        // Writing to Register 0 (should be ignored per the assignment specs)
        #10 wr=1; rd_addr_a=1;    rd_addr_b=5;    wr_addr=0; d_in=16'hba98; 
        
        // Read verification
        #10 wr=0; rd_addr_a=0;    rd_addr_b=5;    wr_addr=3'bx; d_in=16'hxxxx; 
        #10 wr=0; rd_addr_a=0;    rd_addr_b=0;    wr_addr=3'bx; d_in=16'hxxxx;

        #20 $finish;
    end
endmodule