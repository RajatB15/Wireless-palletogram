using MahApps.Metro.Controls;
using System;
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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void SdCardMode_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            SdCardDataDisplayWindow sdcddw = new SdCardDataDisplayWindow(this);
            sdcddw.Show();
        }

        private void StandardSets_Click(object sender, RoutedEventArgs e)
        {
        
            details abc = new details(this);
            abc.Show();
        }

       
        
    }
}
