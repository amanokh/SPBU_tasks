using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project8
{
    public partial class Form1 : Form
    {
        BezierClockControl clkctl;
        public Form1()
        {
            InitializeComponent();
            clkctl = new BezierClockControl();
            clkctl.Parent = this;
            clkctl.Time = DateTime.Now;
            clkctl.Dock = DockStyle.Fill;

            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            clkctl.Time = DateTime.Now;
        }
    }
}

