Public Class Form1
    Dim myPort As Array
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        myPort = IO.Ports.SerialPort.GetPortNames()
        ComboBox2.Items.Add(9600)
        ComboBox2.Items.Add(19200)
        ComboBox2.Items.Add(38400)
        ComboBox2.Items.Add(57600)
        ComboBox2.Items.Add(115200)
        For i = 0 To UBound(myPort)
            ComboBox1.Items.Add(myPort(i))
        Next
        Button1.Enabled = True
        Button2.Enabled = False
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        SerialPort1.PortName = ComboBox1.Text
        SerialPort1.BaudRate = ComboBox2.Text
        SerialPort1.Open()
        Button1.Enabled = False
        Button2.Enabled = True
        Button3.Enabled = True
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        SerialPort1.Close()
        Button1.Enabled = True
        Button2.Enabled = False
        Button3.Enabled = False
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        SerialPort1.Write("1")
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        SerialPort1.Write("2")
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        SerialPort1.Write("3")
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        SerialPort1.Write("4")
    End Sub
End Class
