<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="flight_time_05_12_v3.vi" Type="VI" URL="../flight_time_05_12_v3.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
			<Item Name="8bitTo16bit.vi" Type="VI" URL="../8bitTo16bit.vi"/>
			<Item Name="circularArray.vi" Type="VI" URL="../circularArray.vi"/>
			<Item Name="circularInstance.vi" Type="VI" URL="../circularInstance.vi"/>
			<Item Name="detectMSB.vi" Type="VI" URL="../detectMSB.vi"/>
			<Item Name="detectPreamble.vi" Type="VI" URL="../detectPreamble.vi"/>
			<Item Name="height_flight.vi" Type="VI" URL="../height_flight.vi"/>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="flight_time_05_12_v3" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{FFED2C8C-35D0-4188-9C0C-F273DDB82BF2}</Property>
				<Property Name="App_INI_GUID" Type="Str">{5D7D56D6-065E-4DF8-8D16-ACD9D9B1F08A}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{ADA8EFA7-9249-4B27-8D4C-D75607162E75}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">flight_time_05_12_v3</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/flight_time_05_12_v3</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{AB764398-8FDE-44D3-83D9-07934C11B76E}</Property>
				<Property Name="Bld_version.build" Type="Int">2</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Plataforma_de_forças.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/flight_time_05_12_v3/Plataforma_de_forças.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/flight_time_05_12_v3/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{E1FA05A5-DF94-4443-B9EF-53C281EE25F7}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/flight_time_05_12_v3.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">flight_time_05_12_v3</Property>
				<Property Name="TgtF_internalName" Type="Str">flight_time_05_12_v3</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2016 </Property>
				<Property Name="TgtF_productName" Type="Str">flight_time_05_12_v3</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{D0121E20-DA70-4919-8B64-DE4484AB0DFB}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Plataforma_de_forças.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
