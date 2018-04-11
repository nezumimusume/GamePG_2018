@echo off
@rem サンプルの各フォルダにtkEngineへのシンボリックリンクを作成する。
@setlocal
@set CURRENT_DIR=%~dp0

pushd %CURRENT_DIR%

@call .\cleanup.bat
@call .\Sample\setup.bat

@rem maxScriptをコピー
@copy "%CURRENT_DIR%GameTemplate\tkTools\3dsMaxScripts\tkExporter.ms" "c:\Program Files\Autodesk\3ds Max 2015\scripts\"
@copy "%CURRENT_DIR%GameTemplate\tkTools\3dsMaxScripts\tkExporter.ms" "c:\Program Files\Autodesk\3ds Max 2016\scripts\"
@copy "%CURRENT_DIR%GameTemplate\tkTools\3dsMaxScripts\tkExporter.ms" "c:\Program Files\Autodesk\3ds Max 2017\scripts\"
@copy "%CURRENT_DIR%GameTemplate\tkTools\3dsMaxScripts\tkExporter.ms" "c:\Program Files\Autodesk\3ds Max 2018\scripts\"


@popd
@echo セットアップ終了

@pause