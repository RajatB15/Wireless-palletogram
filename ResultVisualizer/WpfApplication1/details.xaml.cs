﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using MahApps.Metro.Controls;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for details.xaml
    /// </summary>
    public partial class details : MetroWindow
    {
        private MainWindow mainWindow;

        public details(MainWindow mainWindow)
        {
            InitializeComponent();
            this.mainWindow = mainWindow;

        }

    }
}
