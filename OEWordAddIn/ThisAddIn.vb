Public Class ThisAddIn

    Private Sub ThisAddIn_Startup(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Startup

    End Sub

    Private Sub ThisAddIn_Shutdown(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Shutdown

    End Sub

    Private Sub Application_DocumentBeforeClose(ByVal Doc As Microsoft.Office.Interop.Word.Document, ByRef Cancel As Boolean) Handles Application.DocumentBeforeClose
        Dim docInfoTxt As String = ""

        docInfoTxt += "Comments:" + vbLf
        Dim comments As Word.Comments = Doc.Comments
        For Each comment As Word.Comment In comments
            ' 批注内容
            Dim range_range As Word.Range = comment.Range
            Dim txt_range As String = range_range.Text
            docInfoTxt += txt_range + " => "

            ' 被批注原文
            Dim range_scope As Word.Range = comment.Scope
            Dim txt_scope As String = range_scope.Text
            docInfoTxt += txt_scope + vbLf
        Next

        docInfoTxt += vbLf + "Revisions:" + vbLf
        Dim revisions As Word.Revisions = Doc.Revisions
        For Each revision As Word.Revision In revisions
            Dim txt_revision As String = revision.Range.Text
            Dim revisionType As Integer = revision.Type
            docInfoTxt += revisionType.ToString() + " : " + txt_revision + vbLf
        Next

        Dim oeEditing As New OEServiceLib.OEEditing
        oeEditing.CloseEditingDocument("", docInfoTxt)

    End Sub

    Private Sub Application_DocumentBeforeSave(ByVal Doc As Microsoft.Office.Interop.Word.Document, ByRef SaveAsUI As Boolean, ByRef Cancel As Boolean) Handles Application.DocumentBeforeSave
    End Sub

    Private Sub Application_DocumentOpen(ByVal Doc As Microsoft.Office.Interop.Word.Document) Handles Application.DocumentOpen

    End Sub
End Class
