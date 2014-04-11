using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using GameCLI;

namespace GameGUI
{
    public partial class Form1 : Form
    {
        List<Button> btnList = new List<Button>();
        List<Button> FList = new List<Button>();
        public int[,] a = new int[8, 8];
        int player;
        Game g;
        public Form1()
        {
            InitializeComponent();
            g = new Game();
            Inceput();
            player = 1;
        }

        public void Inceput()
        {
            int p = 100;
            string b1 = "1 Player", b2 = "2 Players", b3 = "How to play?", b4 = "Exit";

            for (int i = 0; i < 4; i++)
            {
                Button f = new Button();
                f.Size = new Size(400, 75);
                f.Location = new Point(400, 100 + p);
                f.BackColor = Color.Orange;
                f.Name = (i + 1).ToString();
                f.Font = new Font(f.Font.FontFamily, 20, f.Font.Style | FontStyle.Bold);

                if (i == 0)
                    f.Text = b1;
                if (i == 1)
                    f.Text = b2;
                if (i == 2)
                    f.Text = b3;
                if (i == 3)
                    f.Text = b4;
                f.Click += new System.EventHandler(f_Click);
                this.Controls.Add(f);
                FList.Add(f);
                p += 100;
            }
        }

        public void changeButtons()
        {
            int btnListIndex = 0;
            int nrT = 0, nrO = 0;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (a[i, j] == 0)
                    {
                        btnList[j * 8 + i].BackColor = Color.Black;
                        btnListIndex++;
                    }

                    if (a[i, j] == 1)
                    {
                        btnList[j * 8 + i].BackColor = Color.Turquoise;
                        nrT += 1;
                        btnListIndex++;
                    }

                    if (a[i, j] == 2)
                    {
                        btnList[j * 8 + i].BackColor = Color.Orange;
                        nrO += 1;
                        btnListIndex++;
                    }
                }
            }
        }

        public void IncarcareButoane()
        {
            //Initializare matrice a;
            int nrT = 0, nrO = 0;
            for (int j = 0; j < 8; j++)
                for (int i = 0; i < 8; i++)
                {

                    Button btn = new Button();
                    // btn.Name = n.ToString();
                    btn.Size = new Size(75, 75);
                    btn.Location = new Point(200 + 75 * j, 70 + 75 * i);
                    btnList.Add(btn);


                    if (a[i, j] == 0)
                    {
                        btn.BackColor = Color.Black;
                    }

                    if (a[i, j] == 1)
                    {
                        btn.BackColor = Color.Turquoise;
                        nrT += 1;
                    }

                    if (a[i, j] == 2)
                    {
                        btn.BackColor = Color.Orange;
                        nrO += 1;
                    }

                    btn.Name = (i * 8 + j).ToString();
                    btn.Click += new System.EventHandler(btn_Click);
                    this.Controls.Add(btn);
                }

            Button p1 = new Button();
            p1.BackColor = Color.Turquoise;
            p1.Text = nrT.ToString();
            p1.Size = new Size(75, 75);
            p1.Location = new Point(100, 297);
            p1.Font = new Font(p1.Font.FontFamily, 30, p1.Font.Style | FontStyle.Bold);
            this.Controls.Add(p1);

            Button p2 = new Button();
            p2.BackColor = Color.Orange;
            p2.Text = nrT.ToString();
            p2.Size = new Size(75, 75);
            p2.Location = new Point(100, 372);
            p2.Font = new Font(p2.Font.FontFamily, 30, p2.Font.Style | FontStyle.Bold);
            this.Controls.Add(p2);
        }

        private void btn_Click(object apasat, EventArgs e)
        {

            for (int j = 0; j < 8; j++)
                for (int i = 0; i < 8; i++)
                {
                    int n = i * 8 + j;
                    if (((Button)apasat).Name == (i * 8 + j).ToString())
                    {
                        g.CallMove(ref a, i, j);
                        changeButtons();
                        g.CallComputerMove();
                    }
                }

        }

        public void WhoBegins()
        {
            int p = 100;
            string b1 = "1 Player", b2 = "2 Players";

            Button f1 = new Button();
            f1.Size = new Size(400, 75);
            f1.Location = new Point(400, 100 + p);
            f1.BackColor = Color.Orange;
            f1.Name = "begin" + (1).ToString();
            f1.Font = new Font(f1.Font.FontFamily, 20, f1.Font.Style | FontStyle.Bold);
            //f1.Text = b1;
            f1.Click += new System.EventHandler(f_Click);
            this.Controls.Add(f1);
            FList.Add(f1);
            p += 100;

            Button f2 = new Button();
            f2.Size = new Size(400, 75);
            f2.Location = new Point(400, 100 + p);
            f2.BackColor = Color.Orange;
            f2.Name = "begin" + (2).ToString();
            f2.Font = new Font(f1.Font.FontFamily, 20, f1.Font.Style | FontStyle.Bold);
            //f2.Text = b2;
            f2.Click += new System.EventHandler(f_Click);
            this.Controls.Add(f2);
            FList.Add(f2);
            p += 100;
        }

        private void f_Click(object apasat, EventArgs e)
        {
            for (int i = 0; i < 4; i++)
                FList[i].Visible = false;


            if (((Button)apasat).Name == "1")
            {
                g.CallInit(ref a, false);
                g.CallSetComputerLevel(0);
                IncarcareButoane();
                //WhoBegins();
            }

            if (((Button)apasat).Name == "2")
            {
                //g.CallInit(ref a, true, player);
                //IncarcareButoane();
                WhoBegins();
            }

            if (((Button)apasat).Name == "begin1")
            {

            }

            if (((Button)apasat).Name == "begin2")
            {

            }

            if (((Button)apasat).Name == "3")
                MessageBox.Show("");

            if (((Button)apasat).Name == "4")
                Application.Exit();

        }

    }
}
